/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:29:44 by rjada             #+#    #+#             */
/*   Updated: 2022/01/07 22:11:08 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define ERR_MSG "Error"

void	init_main_stack(t_list **stack_a, size_t argc, char **argv);

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);

void	rot_a(t_list **stack_a);
void	rot_b(t_list **stack_b);
void	rot_ab(t_list **stack_a, t_list **stack_b);

void	rev_rot_a(t_list **stack_a);
void	rev_rot_b(t_list **stack_b);
void	rev_rot_ab(t_list **stack_a, t_list **stack_b);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *stack);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		min_pos(t_list *stack, int min);

void	make_sort(t_list **stack_a, t_list **stack_b, int size_a);

#endif
