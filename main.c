/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/05 00:39:13 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_mega_arg(char *arg)
{
	size_t	i;
	size_t	space;
	size_t	digit;

	space = 0;
	digit = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			++space;
		if (ft_isdigit(arg[i]))
			++digit;
		if (space && digit)
			return (1);
		++i;
	}
	return (0);
}

void	init_main_stack(t_list **stack_a, size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	**mega_arg;

	i = 1;
	while (i < argc)
	{
		if (is_mega_arg(argv[i]))
		{
			j = 0;
			mega_arg = ft_split(argv[i], ' ');
			while (mega_arg[j])
			{
				ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(mega_arg[j])));
				++j;
			}
			ft_split_free(mega_arg);
		}
		else
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
	// check_int_bounds(argc, argv);
	// check_duplicates(argc, argv);


	init_main_stack(&stack_a, argc, argv);
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
