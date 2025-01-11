/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:30:26 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/08 22:51:58 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/param.h>
# include "libft.h"

typedef enum e_command
{
	COM_SA,
	COM_SB,
	COM_SS,
	COM_PA,
	COM_PB,
	COM_RA,
	COM_RB,
	COM_RR,
	COM_RRA,
	COM_RRB,
	COM_RRR,
	COM_ERROR
}	t_command;

typedef struct s_cost
{
	int	pop;
	int	push;
	int	dup;
	int	total;
}	t_cost;

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int num);
void	rb(t_list **stack_b, int num);
void	rr(t_list **stack_a, t_list **stack_b, int num);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		calc_min_index(t_list *stack);
int		calc_cost_push(t_list *sa, t_list *sb, int index);
int		calc_cost_pop(t_list *stack, int index);
t_cost	calc_min_cost(t_list *sa, t_list *sb);
int		ft_abs(int x);
long	ft_strtol(const char *nptr);
int		is_sorted(t_list *stack);
void	print_stack(t_list *stack);
int		sort_command(t_list **stack_a, t_list **stack_b);

#endif
