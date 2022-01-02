/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:23:26 by rjada             #+#    #+#             */
/*   Updated: 2022/01/02 23:34:03 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	swap2upper(t_list **top)
{
	t_list	*second;
	
	second = *top;
	*top = (*top)->next;
	second->next = (*top)->next;
	(*top)->next = second;
}

void	swap_a(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		swap2upper(stack_a);
		ft_putendl_fd("sa", STDOUT);
	}
}

void	swap_b(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		swap2upper(stack_b);
		ft_putendl_fd("sb", STDOUT);
	}
}
