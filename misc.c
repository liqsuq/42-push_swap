/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:06:35 by kadachi           #+#    #+#             */
/*   Updated: 2025/01/09 16:47:20 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	is_overflow(const char *nptr, unsigned long num, int sign)
{
	unsigned long	cutoff;
	unsigned long	cutlim;

	if (sign >= 0)
		cutoff = LONG_MAX;
	else
		cutoff = -(unsigned long)LONG_MIN;
	cutlim = cutoff % 10;
	cutoff /= 10;
	if (num > cutoff || (num == cutoff && (unsigned)(*nptr - '0') > cutlim))
		return (1);
	return (0);
}

long	ft_strtol(const char *nptr)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr) && !is_overflow(nptr, (unsigned long)num, sign))
		num = num * 10 + *nptr++ - '0';
	if (!is_overflow(nptr, num, sign))
		return (num * sign);
	if (sign > 0)
		return (LONG_MAX);
	return (LONG_MIN);
}

int	is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", *(int *)stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}
