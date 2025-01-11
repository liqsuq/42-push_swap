/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:19:30 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/05 10:39:06 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = tmp;
	tmp->next = NULL;
}

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ra(t_list **stack_a, int num)
{
	if (num >= 0)
	{
		while (num--)
		{
			ft_printf("ra\n");
			rotate(stack_a);
		}
	}
	else
	{
		while (num++)
		{
			ft_printf("rra\n");
			reverse_rotate(stack_a);
		}
	}
}

void	rb(t_list **stack_b, int num)
{
	if (num >= 0)
	{
		while (num--)
		{
			ft_printf("rb\n");
			rotate(stack_b);
		}
	}
	else
	{
		while (num++)
		{
			ft_printf("rrb\n");
			reverse_rotate(stack_b);
		}
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int num)
{
	if (num >= 0)
	{
		while (num--)
		{
			ft_printf("rr\n");
			rotate(stack_a);
			rotate(stack_b);
		}
	}
	else
	{
		while (num++)
		{
			ft_printf("rrr\n");
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
	}
}
