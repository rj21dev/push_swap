/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/20 18:19:21 by rjada            ###   ########.fr       */
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
		ra(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == max)
	{
		rra(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == min)
		sa(stack);
}

static void	finalization(t_list **stack_a)
{
	int	min_pos;

	find_minimax_pos(*stack_a, find_min(*stack_a), &min_pos);
	if (min_pos > 0)
		n_rot_1(stack_a, min_pos, ra);
	else
		n_rot_1(stack_a, ft_abs(min_pos), rra);
}

static void	sort_many(t_list **stack_a, t_list **stack_b)
{
	int	rots_a;
	int	rots_b;

	rots_a = 0;
	rots_b = 0;
	if (ft_lstsize(*stack_a) == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sort3(stack_a);
	}
	else
		midpoint_algo(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		count_rotates(*stack_a, *stack_b, &rots_a, &rots_b);
		if ((rots_a >= 0 && rots_b >= 0) || (rots_a < 0 && rots_b < 0))
			one_direction_rots(stack_a, stack_b, rots_a, rots_b);
		else
			two_direction_rots(stack_a, stack_b, rots_a, rots_b);
		pa(stack_a, stack_b);
	}
	finalization(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	init_main_stack(&stack_a, argc, argv);
	size_a = ft_lstsize(stack_a);
	if (2 == size_a)
		sa(&stack_a);
	else if (3 == size_a)
		sort3(&stack_a);
	else
		sort_many(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
}
