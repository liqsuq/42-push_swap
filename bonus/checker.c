/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:38:28 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/08 23:09:11 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(char *arg, t_list *stack_a)
{
	int		i;
	long	num;

	i = 0;
	while (arg[i] == ' ' || (arg[i] >= '\t' && arg[i] <= '\r'))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (1);
	num = ft_strtol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	while (stack_a)
	{
		if (num == *(int *)stack_a->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static int	parse_arg(int argc, char **argv, t_list **stack)
{
	int		i;
	int		*ptr;
	t_list	*node;

	i = 0;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	while (++i < argc)
	{
		if (check_arg(argv[i], *stack))
			return (1);
		ptr = (int *)malloc(sizeof(int));
		if (ptr == NULL)
			return (1);
		*ptr = ft_strtol(argv[i]);
		node = ft_lstnew(ptr);
		if (node == NULL)
		{
			free(ptr);
			return (1);
		}
		ft_lstadd_back(stack, node);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_arg(argc, argv, &stack_a))
	{
		ft_lstclear(&stack_a, free);
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	if (!sort_command(&stack_a, &stack_b))
	{
		if (is_sorted(stack_a) && stack_b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
