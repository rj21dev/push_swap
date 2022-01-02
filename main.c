/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/02 23:35:04 by rjada            ###   ########.fr       */
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

	stack_a = NULL;
	args_validation(argc, argv);
	check_int_bounds(argc, argv);
	check_duplicates(argc, argv);

	if (argc > 1)
		init_stack_a(&stack_a, argc, argv);
	else
		exit(EXIT_SUCCESS);
	ft_lstprint(stack_a);

	// ft_putchar_fd('\n', STDOUT);

	swap_a(&stack_a);
	ft_putchar_fd('\n', STDOUT);
	ft_lstprint(stack_a);

	rot_a(&stack_a);
	ft_putchar_fd('\n', STDOUT);
	ft_lstprint(stack_a);
	
	ft_lstclear(&stack_a, free);
}
