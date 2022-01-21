/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:58:12 by rjada             #+#    #+#             */
/*   Updated: 2022/01/21 14:39:23 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr_of_int(int *arr, int len)
{
	int	i;
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
		++i;
	}
}

static int	find_mid(t_list *stack)
{
	int	i;
	int	mid;
	int	len;
	int	*arr;

	len = ft_lstsize(stack);
	arr = (int *) malloc(sizeof(int) * len);
	i = 0;
	while (stack)
	{
		arr[i++] = ft_atoi(stack->content);
		stack = stack->next;
	}
	sort_arr_of_int(arr, len);
	mid = arr[len / 2];
	free(arr);
	return (mid);
}

static void	push_chunk_to_b(t_list **s_a, t_list **s_b, int chunk, int mid)
{
	t_list	*last;
	int		val;

	while (chunk)
	{
		val = ft_atoi((*s_a)->content);
		if (val < mid)
		{
			pb(s_a, s_b);
			--chunk;
		}
		else
		{
			last = ft_lstlast(*s_a);
			val = ft_atoi(last->content);
			if (val < mid)
				rra(s_a);
			else
				ra(s_a);
		}
	}
}

void	midpoint_algo(t_list **stack_a, t_list **stack_b)
{
	int		mid;
	int		size;
	int		chunk;

	size = ft_lstsize(*stack_a);
	while (size > 2)
	{
		mid = find_mid(*stack_a);
		chunk = size / 2;
		push_chunk_to_b(stack_a, stack_b, chunk, mid);
		size = ft_lstsize(*stack_a);
	}
	if (!is_sorted(*stack_a))
		sa(stack_a);
}
