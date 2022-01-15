/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/11 23:06:59 by rjada            ###   ########.fr       */
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
	sort_arr_of_int(arr, len);
	mid = arr[len / 2];
	free(arr);
	return (mid);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	midpoint_algo(t_list **stack_a, t_list **stack_b)
{
	int		mid;
	int		size;
	int		val;
	int		chunk;
	t_list	*last;
	
	size = ft_lstsize(*stack_a);
	while (size > 2)
	{
		mid = find_mid(*stack_a);
		chunk = size / 2;
		while (chunk)
		{
			val = ft_atoi((*stack_a)->content); 
			if (val < mid)
			{
				push_b(stack_a, stack_b);
				--chunk;
			}
			else
			{
				last = ft_lstlast(*stack_a);
				val = ft_atoi(last->content);
				if (val < mid)
					rev_rot_a(stack_a);
				else
					rot_a(stack_a);
			}
		}
		size = ft_lstsize(*stack_a);
	}
	if (!is_sorted(*stack_a))
		swap_a(stack_a);
}

void	mid_algo_rec(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	size;
	int	mid;
	int	val;
	t_list	*last;
	
	size = ft_lstsize(*stack_a);
	if (size <= 2)
		return ;
	mid = find_mid(*stack_a);
	while (chunk)
	{
		val = ft_atoi((*stack_a)->content); 
		if (val < mid)
		{
			push_b(stack_a, stack_b);
			--chunk;
		}
		else
		{
			last = ft_lstlast(*stack_a);
			val = ft_atoi(last->content);
			if (val < mid)
				rev_rot_a(stack_a);
			else
				rot_a(stack_a);
		}	
	}
	size = ft_lstsize(*stack_a);
	mid_algo_rec(stack_a, stack_b, size / 2);
}

void	back_to_a(t_list **stack_a, t_list **stack_b)
{	
	int	max;
	int	current;
	int	size;
	int	pos;
	
	while (*stack_b)
	{
		max = find_max(*stack_b);
		current = ft_atoi((*stack_b)->content);
		size = ft_lstsize(*stack_b);
		if (size == 97)
			break;
		pos = min_pos(*stack_b, max);
		if (current == max)
		{
			push_a(stack_a, stack_b);
			size = ft_lstsize(*stack_b);
		}
		else
		{
			if (pos <= size / pos + 1)
				rot_b(stack_b);
			else
				rev_rot_b(stack_b);
		}
	}
}

int find_mid_b(t_list *stack, int len)
{
	int *arr = (int *) malloc(sizeof(int) * len);
	int	i = 0;
	int	mid;
	int	chunk_size = len;
	
	while (stack && chunk_size)
	{
		arr[i++] = ft_atoi(stack->content);	
		stack = stack->next;
		--chunk_size;
	}
	sort_arr_of_int(arr, len);
	mid = arr[len / 2];
	free(arr);
	return (mid);
}

int	*count_chunks(int principal_size)
{
	int	tmp = principal_size;
	int	count = 0;

	while (tmp != 1)
	{
		tmp /= 2;
		++count;	
	}
	int cc = count;
	int *chunks = (int *) malloc(sizeof(int) * count);
	
	int	temp = principal_size;
	while (--count >= 0)
	{
		temp /= 2;
		chunks[count] = temp;
	}
	for (int i = 0; i < cc; ++i)
		printf("%i ", chunks[i]);
	return (chunks);
}

void	back_to_a2(t_list **stack_a, t_list **stack_b, int principal_size)
{
	int	*chunks = count_chunks(principal_size);
	int	mid = 0;
	int	rotates = 0;
	int	index = 0;

	
	while (*stack_b)
	{
		//if desc_sorted then push_a
		//size = chunks[index++]

		int	size = chunks[index];
		if (size == 1)
		{
			push_a(stack_a, stack_b);
			++index;
			continue;
		}
		printf("%i", chunks[index]);
		while(size > 2) //size > 2
		{
			int inner_chunk = size / 2;
			mid = find_mid_b(*stack_b, chunks[index]);
			while (inner_chunk)
			{
								// printf("%i", inner_chunk);
				int val = ft_atoi((*stack_a)->content); 
				if (val > mid) // !!! >
				{
					push_a(stack_a, stack_b);
					if (rotates)
						while (rotates)
						{
							rev_rot_b(stack_b);
							rotates--;
						}
					--inner_chunk;
				}
				else
				{
					rot_b(stack_b);
					++rotates;
					break;
				}

			}
			
		}
		++index;
	}
	free(chunks);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	
	init_main_stack(&stack_a, argc, argv);
//	ft_lstprint(stack_a);
//	ft_putchar_fd('\n', STDOUT);

	size_a = ft_lstsize(stack_a);
	// if (!is_sorted(stack_a))
	// 	make_sort(&stack_a, &stack_b, ft_lstsize(stack_a));

	// mid_algo_rec(&stack_a, &stack_b, ft_lstsize(stack_a) / 2);
	midpoint_algo(&stack_a, &stack_b);
	printf("%d\n", size_a);

	back_to_a2(&stack_a, &stack_b, size_a);
	// ft_lstprint(stack_a);
	// ft_putendl_fd("", STDOUT);
	// ft_lstprint(stack_b);

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
