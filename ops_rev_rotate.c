/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:03:10 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:39:31 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_list **top)
{
	t_list	*before_last;
	t_list	*last;

	last = *top;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *top;
	*top = last;
	before_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		rev_rotate_stack(stack_a);
		ft_putendl_fd("rra", STDOUT);
	}
}

void	rrb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		rev_rotate_stack(stack_b);
		ft_putendl_fd("rrb", STDOUT);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		ft_putendl_fd("rrr", STDOUT);
	}
}
