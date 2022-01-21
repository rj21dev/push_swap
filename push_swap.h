/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:29:44 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:42:28 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define ERR_MSG "Error"

void	init_main_stack(t_list **stack_a, size_t argc, char **argv);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		min(int a, int b);
int		ft_abs(int n);

void	find_minimax_pos(t_list *stack_a, int num, int *steps_a);
void	count_rotates(t_list *s_a, t_list *s_b, int *rots_a, int *rots_b);

void	n_rot_1(t_list **stack, int n, void (*f)(t_list **));
void	n_rot_2(t_list **a, t_list **b, int n, void (*f)(t_list **, t_list **));
void	one_direction_rots(t_list **s_a, t_list **s_b, int rots_a, int rots_b);
void	two_direction_rots(t_list **s_a, t_list **s_b, int rots_a, int rots_b);

void	midpoint_algo(t_list **stack_a, t_list **stack_b);

#endif
