/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:03:10 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:39:37 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_list **top)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *top;
	second = (*top)->next;
	last = (*top)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*top = second;
}

void	ra(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		rotate_stack(stack_a);
		ft_putendl_fd("ra", STDOUT);
	}
}

void	rb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		rotate_stack(stack_b);
		ft_putendl_fd("rb", STDOUT);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		ft_putendl_fd("rr", STDOUT);
	}
}
