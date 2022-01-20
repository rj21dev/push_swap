/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:52:38 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 00:37:45 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	find_min(t_list *stack)
{
	int	min;
	int	current;

	min = ft_atoi(stack->content);
	while (stack->next)
	{
		stack = stack->next;
		current = ft_atoi(stack->content);
		if (min > current)
			min = current;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;
	int	current;

	max = ft_atoi(stack->content);
	while (stack->next)
	{
		stack = stack->next;
		current = ft_atoi(stack->content);
		if (max < current)
			max = current;
	}
	return (max);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
