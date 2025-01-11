/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:12:02 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/07 22:27:01 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_min_index(t_list *stack)
{
	int	min_value;
	int	min_index;
	int	i;

	min_value = *(int *)stack->content;
	min_index = 0;
	i = 0;
	while (stack != NULL)
	{
		if (*(int *)stack->content < min_value)
		{
			min_value = *(int *)stack->content;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	calc_cost_pop(t_list *stack, int index)
{
	int	size;

	size = ft_lstsize(stack);
	if (index <= size - index)
		return (index);
	return (-(size - index));
}

int	calc_cost_push(t_list *sa, t_list *sb, int index)
{
	int	size;
	int	min;
	int	i;

	size = ft_lstsize(sb);
	if (size < 2)
		return (0);
	min = calc_min_index(sb);
	while (0 < index--)
		sa = sa->next;
	if (*(int *)ft_lstlast(sb)->content > *(int *)sa->content
		&& *(int *)sa->content > *(int *)sb->content)
		return (0);
	i = 1;
	while (sb->next != NULL && (*(int *)sb->content < *(int *)sa->content
			|| *(int *)sa->content < *(int *)sb->next->content))
	{
		sb = sb->next;
		i++;
	}
	if (sb->next == NULL)
		i = min + 1;
	if (i <= size - i)
		return (i);
	return (-(size - i));
}

t_cost	calc_min_cost(t_list *sa, t_list *sb)
{
	t_cost	tmp;
	t_cost	min;
	int		i;

	i = -1;
	while (++i < ft_lstsize(sa))
	{
		tmp.pop = calc_cost_pop(sa, i);
		tmp.push = calc_cost_push(sa, sb, i);
		if (tmp.pop * tmp.push > 0)
		{
			if (tmp.pop > 0)
				tmp.dup = MAX(tmp.pop, tmp.push) - ft_abs(tmp.pop - tmp.push);
			else
				tmp.dup = MIN(tmp.pop, tmp.push) + ft_abs(tmp.pop - tmp.push);
		}
		else
			tmp.dup = 0;
		tmp.total = ft_abs(tmp.pop) + ft_abs(tmp.push) - ft_abs(tmp.dup);
		if (i == 0 || min.total > tmp.total)
			min = (t_cost){tmp.pop, tmp.push, tmp.dup, tmp.total};
	}
	return (min);
}
