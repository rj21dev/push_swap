/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:48:19 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:55:49 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	pop_and_push(t_list **src, t_list **dest)
{
	t_list	*pop;

	pop = *src;
	*src = (*src)->next;
	pop->next = NULL;
	ft_lstadd_front(dest, ft_lstnew(ft_strdup(pop->content)));
	ft_lstdelone(pop, free);
}

void	pb_chk(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		pop_and_push(stack_a, stack_b);
}

void	pa_chk(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
		pop_and_push(stack_b, stack_a);
}
