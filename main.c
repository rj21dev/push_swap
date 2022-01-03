/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/03 21:55:31 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	init_stack_a(t_list **stack_a, size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(argv[i])));
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	args_validation(argc, argv);
	check_int_bounds(argc, argv);
	check_duplicates(argc, argv);

	if (argc > 1)
		init_stack_a(&stack_a, argc, argv);
	else
		exit(EXIT_SUCCESS);
	ft_lstprint(stack_a);

	ft_putchar_fd('\n', STDOUT);

	swap_a(&stack_a);
	ft_lstprint(stack_a);

	ft_putchar_fd('\n', STDOUT);
	rot_a(&stack_a);
	ft_lstprint(stack_a);
	

	ft_putchar_fd('\n', STDOUT);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	ft_lstprint(stack_a);
	ft_putchar_fd('\n', STDOUT);
	ft_lstprint(stack_b);
	
	ft_putchar_fd('\n', STDOUT);
	swap_ab(&stack_a, &stack_b);
	ft_lstprint(stack_a);
	ft_putchar_fd('\n', STDOUT);
	ft_lstprint(stack_b);

	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
}
