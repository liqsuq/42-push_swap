/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:16:37 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/08 22:53:46 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_command	check_command(char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (COM_SA);
	if (!ft_strncmp(line, "sb\n", 3))
		return (COM_SB);
	if (!ft_strncmp(line, "ss\n", 3))
		return (COM_SS);
	if (!ft_strncmp(line, "pa\n", 3))
		return (COM_PA);
	if (!ft_strncmp(line, "pb\n", 3))
		return (COM_PB);
	if (!ft_strncmp(line, "ra\n", 3))
		return (COM_RA);
	if (!ft_strncmp(line, "rb\n", 3))
		return (COM_RB);
	if (!ft_strncmp(line, "rr\n", 3))
		return (COM_RR);
	if (!ft_strncmp(line, "rra\n", 4))
		return (COM_RRA);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (COM_RRB);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (COM_RRR);
	return (COM_ERROR);
}

static int	parse_command(t_list **command)
{
	char		*line;
	t_command	*ptr;
	t_list		*node;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (check_command(line) == COM_ERROR)
			return (free(line), 1);
		ptr = (t_command *)malloc(sizeof(t_command));
		if (ptr == NULL)
			return (free(line), 1);
		*ptr = check_command(line);
		free(line);
		node = ft_lstnew(ptr);
		if (node == NULL)
			return (free(ptr), 1);
		ft_lstadd_back(command, node);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}

static void	exec_command(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (*(t_command *)command->content == COM_SA)
		sa(stack_a);
	else if (*(t_command *)command->content == COM_SB)
		sb(stack_b);
	else if (*(t_command *)command->content == COM_SS)
		ss(stack_a, stack_b);
	else if (*(t_command *)command->content == COM_PA)
		pa(stack_a, stack_b);
	else if (*(t_command *)command->content == COM_PB)
		pb(stack_a, stack_b);
	else if (*(t_command *)command->content == COM_RA)
		ra(stack_a, 1);
	else if (*(t_command *)command->content == COM_RB)
		rb(stack_b, 1);
	else if (*(t_command *)command->content == COM_RR)
		rr(stack_a, stack_b, 1);
	else if (*(t_command *)command->content == COM_RRA)
		ra(stack_a, -1);
	else if (*(t_command *)command->content == COM_RRB)
		rb(stack_b, -1);
	else if (*(t_command *)command->content == COM_RRR)
		rr(stack_a, stack_b, -1);
}

int	sort_command(t_list **stack_a, t_list **stack_b)
{
	t_list	*command;

	command = NULL;
	if (parse_command(&command))
	{
		ft_lstclear(&command, free);
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	while (command != NULL)
	{
		exec_command(stack_a, stack_b, command);
		command = command->next;
	}
	ft_lstclear(&command, free);
	return (0);
}
