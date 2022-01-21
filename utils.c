/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:52:38 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 19:18:03 by rjada            ###   ########.fr       */
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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	are_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (TRUE);
			++j;
		}
		++i;
	}
	return (FALSE);
}
