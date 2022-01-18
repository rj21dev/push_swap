/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:12:24 by rjada             #+#    #+#             */
/*   Updated: 2022/01/18 20:47:13 by rjada            ###   ########.fr       */
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

int	find_mid(t_list *stack)
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
	while (size > 3)
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

void	midpoint_new(t_list **stack_a, t_list **stack_b)
{
	
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

void	find_minimax_pos(t_list *stack_a, int num, int *steps_a)
{
	int	old_minimax;
	int	size_a;

	*steps_a = 0;
	size_a = ft_lstsize(stack_a);
	if (num < find_min(stack_a))
		old_minimax = find_min(stack_a);
	else
	{
		old_minimax = find_max(stack_a);
		++(*steps_a);
	}
	while (stack_a)
	{
		if (ft_atoi(stack_a->content) == old_minimax)
			break ;
		++(*steps_a);
		stack_a = stack_a->next;
	}
	if (*steps_a >= (size_a + 1) / 2)
		*steps_a = -1 * (size_a - (*steps_a));
}

void	find_mid_pos_to_ins(t_list *stack_a, int num, int *steps_a)
{
	int	cur_val;
	int	next_val;
	int	size_a;

	size_a = ft_lstsize(stack_a);
	*steps_a = 1;
	while (stack_a->next)
	{
		cur_val = ft_atoi(stack_a->content);
		next_val = ft_atoi(stack_a->next->content);
		if (num > cur_val && num < next_val)
			break ;
		++(*steps_a);
		stack_a = stack_a->next;
	}
	if (*steps_a >= (size_a + 1) / 2)
		*steps_a = -1 * (size_a - (*steps_a));
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	count_rotates(t_list *stack_a, t_list *stack_b, int *rotates_a, int *rotates_b)
{
	int	steps_a;
	int	steps_b;
	int	num;
	int	size_b;

	size_b = ft_lstsize(stack_b);
	steps_b = 0;
	while (stack_b)
	{
		num = ft_atoi(stack_b->content);
		if (num < find_min(stack_a) || num > find_max(stack_a))
			find_minimax_pos(stack_a, num, &steps_a);
		else
			find_mid_pos_to_ins(stack_a, num, &steps_a);
		if (!steps_b || ft_abs(*rotates_a) + ft_abs(*rotates_b) > ft_abs(steps_a) + ft_abs(steps_b))
		{
			*rotates_a = steps_a;
			if (steps_b < (size_b + 1) / 2)
				*rotates_b = steps_b;
			else
				*rotates_b = -1 * (size_b - steps_b);
			*rotates_b = steps_b;
		}
		stack_b = stack_b->next;
		++steps_b;
	}
}

void	multi_rotates_one(t_list **stack, int n, void (*f)(t_list **))
{
	while (n)
	{
		(*f)(stack);
		--n;
	}
}

void	multi_rotates_both(t_list **stack_a, t_list **stack_b, int n, void (*f)(t_list **, t_list **))
{
	while (n)
	{
		(*f)(stack_a, stack_b);
		--n;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	synchro_rotates(t_list **stack_a, t_list **stack_b, int rotates_a, int rotates_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(rotates_a);
	abs_b = ft_abs(rotates_b);
	if (rotates_a >= 0 && rotates_b >= 0)
	{
		multi_rotates_both(stack_a, stack_b, min(rotates_a, rotates_b), rot_ab);
		if (rotates_a < rotates_b)
			multi_rotates_one(stack_b, rotates_b - rotates_a, rot_b);
		else
			multi_rotates_one(stack_a, rotates_a - rotates_b, rot_a);
	}
	else
	{
		multi_rotates_both(stack_a, stack_b, min(abs_a, abs_b), rev_rot_ab);
		if (abs_a < abs_b)
			multi_rotates_one(stack_b, abs_b - abs_a, rev_rot_b);
		else
			multi_rotates_one(stack_a, abs_a - abs_b, rev_rot_a);
	}
}

void	discrete_rotates(t_list **stack_a, t_list **stack_b, int rotates_a, int rotates_b)
{
	if (rotates_a >= 0 && rotates_b < 0)
	{
		multi_rotates_one(stack_a, rotates_a, rot_a);
		multi_rotates_one(stack_b, ft_abs(rotates_b), rev_rot_b);
	}
	else
	{
		multi_rotates_one(stack_a, ft_abs(rotates_a), rev_rot_a);
		multi_rotates_one(stack_b, rotates_b, rot_b);
	}
}

void	finalization(t_list **stack_a)
{
	int	min_pos;

	find_minimax_pos(*stack_a, find_min(*stack_a), &min_pos);
	if (min_pos > 0)
		multi_rotates_one(stack_a, min_pos, rot_a);
	else
		multi_rotates_one(stack_a, ft_abs(min_pos), rev_rot_a);
}



void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	rotates_a;
	int	rotates_b;
	// int	size_a;

	rotates_a = 0;
	rotates_b = 0;
	midpoint_algo(stack_a, stack_b);
	// size_a = ft_lstsize(*stack_a);
	// while (size_a > 3)
	// {
	// 	push_b(stack_a, stack_b);
	// 	--size_a;
	// }
	if (!is_sorted(*stack_a))
		sort3(stack_a);
	while (*stack_b)
	{
		count_rotates(*stack_a, *stack_b, &rotates_a, &rotates_b);
		if ((rotates_a >= 0 && rotates_b >= 0) || (rotates_a < 0 && rotates_b < 0))
			synchro_rotates(stack_a, stack_b, rotates_a, rotates_b);
		else
			discrete_rotates(stack_a, stack_b, rotates_a, rotates_b);
		push_a(stack_a, stack_b);
	}
	finalization(stack_a);
}



int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	// int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	
	init_main_stack(&stack_a, argc, argv);
//	ft_lstprint(stack_a);
//	ft_putchar_fd('\n', STDOUT);

	// size_a = ft_lstsize(stack_a);
	// if (!is_sorted(stack_a))
	// 	make_sort(&stack_a, &stack_b, ft_lstsize(stack_a));

	// mid_algo_rec(&stack_a, &stack_b, ft_lstsize(stack_a) / 2);
	// midpoint_algo(&stack_a, &stack_b);
	// printf("%d\n", size_a);

	// back_to_a(&stack_a, &stack_b);
	big_sort(&stack_a, &stack_b);
	// multi_rotates_one(&stack_a, 3, rev_rot_a);
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
// change_one_n(t_list **stack, int n, (*f)(t_list **));
// change_both_n(t_list **stack_a, t_list **stack_b, int n, (*f)(t_list **, t_list **))

//5500
