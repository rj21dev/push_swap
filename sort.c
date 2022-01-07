/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:09:21 by rjada             #+#    #+#             */
/*   Updated: 2022/01/07 22:12:17 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_list **stack)
{
	int	min;
	int	max;
	int	first;
	int	second;
	
	min = find_min(*stack);
	max = find_max(*stack);
	first = ft_atoi((*stack)->content);
	second = ft_atoi((*stack)->next->content);
	if (first == max)
	{
		rot_a(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == max)
	{
		rev_rot_a(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == min)
		swap_a(stack);
}

// static void	govno_sort(t_list **stack_a, t_list **stack_b)
// {	
// 	int	min;
// 	int	current;
	
// 	while (*stack_a)
// 	{
// 		min = find_min(*stack_a);
// 		current = ft_atoi((*stack_a)->content);
// 		if (current == min)
// 			push_b(stack_a, stack_b);
// 		else
// 			rot_a(stack_a);
// 	}
// 	while (*stack_b)
// 		push_a(stack_a, stack_b);
// }

static void	govno_sort2(t_list **stack_a, t_list **stack_b)
{	
	int	min;
	int	current;
	int	size;
	int	pos;
	
	while (*stack_a)
	{
		min = find_min(*stack_a);
		current = ft_atoi((*stack_a)->content);
		size = ft_lstsize(*stack_a);
		pos = min_pos(*stack_a, min);
		if (current == min)
		{
			push_b(stack_a, stack_b);
			size = ft_lstsize(*stack_a);
		}
		else
		{
			if (pos <= size / pos + 1)
				rot_a(stack_a);
			else
				rev_rot_a(stack_a);
		}
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	make_sort(t_list **stack_a, t_list **stack_b, int size_a)
{
	if (2 == size_a)
		swap_a(stack_a);
	else if (3 == size_a)
		sort3(stack_a);
	else
		govno_sort2(stack_a, stack_b);
}