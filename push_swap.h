/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:29:44 by rjada             #+#    #+#             */
/*   Updated: 2022/01/02 23:39:46 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define ERR_MSG "Error"

void	args_validation(size_t argc, char **argv);
void	check_int_bounds(size_t argc, char **argv);
void	check_duplicates(size_t argc, char **argv);

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	rot_a(t_list **stack_a);
void	rot_b(t_list **stack_b);
void	rot_ab(t_list **stack_a, t_list **stack_b);

#endif
