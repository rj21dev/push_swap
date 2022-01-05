/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/05 23:07:36 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return(0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	init_main_stack(&stack_a, argc, argv);
	ft_lstprint(stack_a);
	ft_putchar_fd('\n', STDOUT);

	if (2 == ft_lstsize(stack_a))
		if (!is_sorted(stack_a))
			swap_a(&stack_a);
	
	ft_lstprint(stack_a);
	// ft_putchar_fd('\n', STDOUT);

	// swap_a(&stack_a);
	// ft_lstprint(stack_a);
	// ft_putchar_fd('\n', STDOUT);

	// rot_a(&stack_a);
	// ft_lstprint(stack_a);
	// ft_putchar_fd('\n', STDOUT);

	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// ft_lstprint(stack_a);
	// ft_putchar_fd('\n', STDOUT);
	// ft_lstprint(stack_b);
	// ft_putchar_fd('\n', STDOUT);

	// swap_ab(&stack_a, &stack_b);
	// ft_lstprint(stack_a);
	// ft_putchar_fd('\n', STDOUT);
	// ft_lstprint(stack_b);
	
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
}
