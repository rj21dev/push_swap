/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2021/12/29 22:13:28 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

void	print_err_and_exit(char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR);
	exit(EXIT_FAILURE);
}

void	args_validation(size_t argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				print_err_and_exit(ERR_MSG);
			++j;
		}
		++i;
	}
}

void	check_int_bounds(size_t argc, char **argv)
{
	size_t	i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < MIN_OF_INT || num > MAX_OF_INT)
			print_err_and_exit(ERR_MSG);
		++i;
	}
}

void	check_duplicates(size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strncmp(argv[i], argv[i + 1], 11) == 0)
				print_err_and_exit(ERR_MSG);
		++i;
	}
}

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

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, STDOUT);
		tmp = tmp->next;
	}
}

void	swap2upper(t_list **top)
{
	t_list	*second;
	
	second = *top;
	if (*top && (*top)->next)
	{
		*top = (*top)->next;
		second->next = (*top)->next;
		(*top)->next = second;
	}
}

void	swap_a(t_list **stack_a)
{
	swap2upper(stack_a);
	ft_putendl_fd("sa", STDOUT);
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
	print_stack(stack_a);

	swap_a(&stack_a);
	ft_putchar_fd('\n', STDOUT);
	print_stack(stack_a);
	ft_lstclear(&stack_a, free);

	printf("%i\n", atoi("2147483647"));
	printf("%li\n", ft_atol("2147483648"));


}
