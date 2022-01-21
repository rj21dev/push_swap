/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:52 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:56:42 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"

void	sa_chk(t_list **stack_a);
void	sb_chk(t_list **stack_b);
void	ss_chk(t_list **stack_a, t_list **stack_b);

void	ra_chk(t_list **stack_a);
void	rb_chk(t_list **stack_b);
void	rr_chk(t_list **stack_a, t_list **stack_b);

void	rra_chk(t_list **stack_a);
void	rrb_chk(t_list **stack_b);
void	rrr_chk(t_list **stack_a, t_list **stack_b);

void	pa_chk(t_list **stack_a, t_list **stack_b);
void	pb_chk(t_list **stack_a, t_list **stack_b);

#endif
