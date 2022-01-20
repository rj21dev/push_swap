/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:48:36 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 00:59:00 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_op(t_list **stack_a, t_list **stack_b, char *op)
{
	if (3 == ft_strlen(op) && !ft_strncmp(op, "sa\n", ft_strlen(op)))
		sa(stack_a);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "sb\n", ft_strlen(op)))
		sb(stack_b);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "ss\n", ft_strlen(op)))
		ss(stack_a, stack_b);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "ra\n", ft_strlen(op)))
		ra(stack_a);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "rb\n", ft_strlen(op)))
		rb(stack_b);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "rr\n", ft_strlen(op)))
		rr(stack_a, stack_b);
	else if (4 == ft_strlen(op) && !ft_strncmp(op, "rra\n", ft_strlen(op)))
		rra(stack_a);
	else if (4 == ft_strlen(op) && !ft_strncmp(op, "rrb\n", ft_strlen(op)))
		rrb(stack_b);
	else if (4 == ft_strlen(op) && !ft_strncmp(op, "rrr\n", ft_strlen(op)))
		rrr(stack_a, stack_b);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "pa\n", ft_strlen(op)))
		pa(stack_a, stack_b);
	else if (3 == ft_strlen(op) && !ft_strncmp(op, "pb\n", ft_strlen(op)))
		pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	is_valid_ops(t_list **stack_a, t_list **stack_b)
{
	char	*op;
	
	while (1)
	{
		op = get_next_line(STDIN);
		if (!op)
			return (1);
		if (!do_op(stack_a, stack_b, op))
		{
			ft_putendl_fd(ERR_MSG, STDERR);
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_main_stack(&stack_a, argc, argv);
	if (is_valid_ops(&stack_a, &stack_b))
	{
		if (is_sorted(stack_a))
			ft_putendl_fd("OK", STDOUT);
		else
			ft_putendl_fd("KO", STDOUT);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
