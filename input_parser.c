/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:51:12 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:39:13 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	args_validation(size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (!len)
			ft_error(ERR_MSG);
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])))
				|| (argv[i][j] == ' ' && argc != 2))
				ft_error(ERR_MSG);
			++j;
		}
		++i;
	}
}

static void	check_int_bounds(t_list *stack)
{
	long	num;

	while (stack)
	{
		num = ft_atol(stack->content);
		if (num < MIN_OF_INT || num > MAX_OF_INT)
			ft_error(ERR_MSG);
		stack = stack->next;
	}
}

static void	check_duplicates(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) == ft_atoi(stack->next->content))
			ft_error(ERR_MSG);
		stack = stack->next;
	}
}

static int	is_composite_arg(char *arg)
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
			return (TRUE);
		++i;
	}
	return (FALSE);
}

void	init_main_stack(t_list **stack_a, size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	**composite_arg;

	args_validation(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (is_composite_arg(argv[i]))
		{
			j = 0;
			composite_arg = ft_split(argv[i], ' ');
			while (composite_arg[j])
			{
				ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(composite_arg[j])));
				++j;
			}
			ft_split_free(composite_arg);
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(argv[i])));
		++i;
	}
	check_int_bounds(*stack_a);
	check_duplicates(*stack_a);
}
