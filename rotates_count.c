/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:25:58 by rjada             #+#    #+#             */
/*   Updated: 2022/01/20 18:07:21 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_minimax_pos(t_list *stack_a, int num, int *steps_a)
{
	int	old_minimax;
	int	size_a;

	*steps_a = 0;
	size_a = ft_lstsize(stack_a);
	if (num < find_min(stack_a))
		old_minimax = find_min(stack_a);
	else
	{
		old_minimax = find_max(stack_a);
		++(*steps_a);
	}
	while (stack_a)
	{
		if (ft_atoi(stack_a->content) == old_minimax)
			break ;
		++(*steps_a);
		stack_a = stack_a->next;
	}
	if (*steps_a >= (size_a + 1) / 2)
		*steps_a = -1 * (size_a - (*steps_a));
}

static void	find_mid_pos_to_ins(t_list *stack_a, int num, int *steps_a)
{
	int	cur_val;
	int	next_val;
	int	size_a;

	size_a = ft_lstsize(stack_a);
	*steps_a = 1;
	while (stack_a->next)
	{
		cur_val = ft_atoi(stack_a->content);
		next_val = ft_atoi(stack_a->next->content);
		if (num > cur_val && num < next_val)
			break ;
		++(*steps_a);
		stack_a = stack_a->next;
	}
	if (*steps_a >= (size_a + 1) / 2)
		*steps_a = -1 * (size_a - (*steps_a));
}

static void	define_sign_of_steps_b(int index, int size_b, int *steps_b)
{
	if (index >= (size_b + 1) / 2)
			*steps_b = -1 * (size_b - index);
}

void	count_rotates(t_list *s_a, t_list *s_b, int *rots_a, int *rots_b)
{
	int	a;
	int	b;
	int	num;
	int	size_b;
	int	index;

	size_b = ft_lstsize(s_b);
	index = 0;
	while (s_b)
	{
		num = ft_atoi(s_b->content);
		if (num < find_min(s_a) || num > find_max(s_a))
			find_minimax_pos(s_a, num, &a);
		else
			find_mid_pos_to_ins(s_a, num, &a);
		b = index;
		define_sign_of_steps_b(index, size_b, &b);
		if (!b || ft_abs(*rots_a) + ft_abs(*rots_b) > ft_abs(a) + ft_abs(b))
		{
			*rots_a = a;
			*rots_b = b;
		}
		s_b = s_b->next;
		++index;
	}
}
