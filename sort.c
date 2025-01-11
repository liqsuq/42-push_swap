/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:24:09 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/08 00:30:29 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **s)
{
	int	flag;
	int	num_flag;

	flag = 0b000;
	flag = (*(int *)(*s)->content < *(int *)(*s)->next->content) << 2
		| (*(int *)(*s)->next->content < *(int *)(*s)->next->next->content) << 1
		| (*(int *)(*s)->next->next->content < *(int *)(*s)->content);
	num_flag = (flag & 0x55) + (flag >> 1 & 0x55);
	num_flag = (num_flag & 0x33) + (num_flag >> 2 & 0x33);
	if (!(flag & 0b100) && (flag & 0b001))
		ra(s, 1);
	if ((flag & 0b100) && !(flag & 0b010))
		ra(s, -1);
	if (num_flag == 1)
		sa(s);
}

static void	sort_some(t_list **sa, t_list **sb)
{
	int	cnt;

	cnt = 0;
	while (ft_lstsize(*sa) > 3)
	{
		ra(sa, calc_cost_pop(*sa, calc_min_index(*sa)));
		pb(sa, sb);
		cnt++;
	}
	sort_three(sa);
	while (cnt-- > 0)
		pa(sa, sb);
}

static void	sort_many(t_list **sa, t_list **sb)
{
	t_cost	min;
	int		cnt;

	cnt = 6;
	while (ft_lstsize(*sa) > cnt)
	{
		min = calc_min_cost(*sa, *sb);
		rr(sa, sb, min.dup);
		ra(sa, min.pop - min.dup);
		rb(sb, min.push - min.dup);
		pb(sa, sb);
	}
	rb(sb, 1 + calc_cost_pop(*sb, calc_min_index(*sb)));
	sort_some(sa, sb);
	while (ft_lstsize(*sb) > 0)
	{
		while (cnt && *(int *)ft_lstlast(*sa)->content > *(int *)(*sb)->content)
		{
			ra(sa, -1);
			cnt--;
		}
		pa(sa, sb);
	}
	ra(sa, -cnt);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	if (size == 2)
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size >= 4 && size <= 6)
		sort_some(stack_a, stack_b);
	if (size >= 7)
		sort_many(stack_a, stack_b);
}
