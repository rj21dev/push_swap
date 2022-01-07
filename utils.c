/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:52:38 by rjada             #+#    #+#             */
/*   Updated: 2022/01/07 21:53:46 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return(0);
		stack = stack->next;
	}
	return (1);
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

int	min_pos(t_list *stack, int min)
{
	int	pos;
	
	pos = 0;
	while (stack->next)
	{
		int	current = ft_atoi(stack->content);
		if (current == min)
			break;
		stack = stack->next;
		++pos;
	}
	return (pos);
}
