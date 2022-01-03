/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:03:10 by rjada             #+#    #+#             */
/*   Updated: 2022/01/03 21:45:15 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	rev_rotate_stack(t_list **top)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;

	first = *top;
	last = (*top)->next;
	while (last->next)
	{
		if (!last->next->next)
			before_last = last;
		last = last->next;
	}
	last->next = first;
	*top = last;
	before_last->next = NULL;
}

void	rev_rot_a(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		rev_rotate_stack(stack_a);
		ft_putendl_fd("rra", STDOUT);
	}
}

void	rev_rot_b(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		rev_rotate_stack(stack_b);
		ft_putendl_fd("rrb", STDOUT);
	}
}

void	rev_rot_ab(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		ft_putendl_fd("rrr", STDOUT);
	}
}
