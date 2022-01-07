/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/07 22:09:04 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr_of_int(int *arr, int len)
{
	int i;
	int	j;
	int	smallest;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		smallest = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[smallest])
				smallest = j;
			++j;
		}
		tmp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = tmp;
		// swap(&arr[i], &arr[smallest]);
		++i;
	}
}

int find_mid(t_list *stack)
{
	int	len = ft_lstsize(stack);
	int *arr = (int *) malloc(sizeof(int) * len);
	int	i = 0;
	int	mid;
	
	while (stack)
	{
		arr[i++] = ft_atoi(stack->content);	
		stack = stack->next;
	}
	//sort
	sort_arr_of_int(arr, len);
	mid = arr[len / 2];
	free(arr);
	return (mid);
}

void	midpoint_algo(t_list **stack_a, t_list **stack_b)
{
	int	mid = find_mid(*stack_a);
	//int	size = ft_lstsize(*stack_a);
	
		int	val = ft_atoi((*stack_a)->content);
		if (val < mid)
			push_b(stack_a, stack_b);
		else
		{
			// if val_last < mid then rra else ra
		}	
			
	///	size = ft_lstsize(*stack_a);

}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	init_main_stack(&stack_a, argc, argv);
//	ft_lstprint(stack_a);
//	ft_putchar_fd('\n', STDOUT);


	if (!is_sorted(stack_a))
		make_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
	// {
	// 	if (2 == ft_lstsize(stack_a))
	// 		swap_a(&stack_a);
	// 	else if (3 == ft_lstsize(stack_a))
	// 		sort3(&stack_a);
	// 	else
	// 		govno_sort2(&stack_a, &stack_b);
	// }


//	midpoint_algo(&stack_a, &stack_b);
	
	
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
}
