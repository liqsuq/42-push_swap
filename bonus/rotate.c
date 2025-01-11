/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:19:30 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/08 23:09:43 by kadachi          ###   ########.fr       */
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
		while (num--)
			rotate(stack_a);
	else
		while (num++)
			reverse_rotate(stack_a);
}

void	rb(t_list **stack_b, int num)
{
	if (num >= 0)
		while (num--)
			rotate(stack_b);
	else
		while (num++)
			reverse_rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b, int num)
{
	if (num >= 0)
	{
		while (num--)
		{
			rotate(stack_a);
			rotate(stack_b);
		}
	}
	else
	{
		while (num++)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
	}
}
