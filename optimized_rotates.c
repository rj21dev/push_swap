/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:14:47 by rjada             #+#    #+#             */
/*   Updated: 2022/01/20 18:08:38 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_rot_1(t_list **stack, int n, void (*f)(t_list **))
{
	while (n)
	{
		(*f)(stack);
		--n;
	}
}

void	n_rot_2(t_list **a, t_list **b, int n, void (*f)(t_list **, t_list **))
{
	while (n)
	{
		(*f)(a, b);
		--n;
	}
}

void	one_direction_rots(t_list **s_a, t_list **s_b, int rots_a, int rots_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(rots_a);
	abs_b = ft_abs(rots_b);
	if (rots_a >= 0 && rots_b >= 0)
	{
		n_rot_2(s_a, s_b, min(rots_a, rots_b), rr);
		if (rots_a < rots_b)
			n_rot_1(s_b, rots_b - rots_a, rb);
		else
			n_rot_1(s_a, rots_a - rots_b, ra);
	}
	else
	{
		n_rot_2(s_a, s_b, min(abs_a, abs_b), rrr);
		if (abs_a < abs_b)
			n_rot_1(s_b, abs_b - abs_a, rrb);
		else
			n_rot_1(s_a, abs_a - abs_b, rra);
	}
}

void	two_direction_rots(t_list **s_a, t_list **s_b, int rots_a, int rots_b)
{
	if (rots_a >= 0 && rots_b < 0)
	{
		n_rot_1(s_a, rots_a, ra);
		n_rot_1(s_b, ft_abs(rots_b), rrb);
	}
	else
	{
		n_rot_1(s_b, rots_b, rb);
		n_rot_1(s_a, ft_abs(rots_a), rra);
	}
}
