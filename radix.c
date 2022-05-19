/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:03:04 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/18 14:01:3 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	int		bit;
	int		i;
	int		size_a;
	int		size_b;

	bit = 0;
	ft_range(stack_a);
	while (!check_sorted(stack_a))
	{
		i = 0;
		size_a = ft_lstsize(*stack_a);
		while (i < size_a)
		{
			if ((((*stack_a)->content >> bit) & 1) == 1)
				ra(stack_a, stack_b, tmp);
			else
				pb(stack_a, stack_b, tmp);
			++i;
		}
		i = 0;
		bit++;
		size_b = ft_lstsize(*stack_b);
		if (!check_sorted(stack_a) || !reverse_sorted(stack_b))
			while (i < size_b)
			{
				if ((((*stack_b)->content >> bit) & 1) != 1)
					rb(stack_a, stack_b, tmp);
				else
					pa(stack_a, stack_b, tmp);
				++i;
			}
		else
		{
			while (*stack_b)
				pa(stack_a, stack_b, tmp);
			return ;
		}
	}
}

void	median_sort(int *array, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_range(t_list **stack_a)
{
	int		*arr;

	arr = malloc(ft_lstsize(*stack_a) * sizeof(int));
	if (!arr)
		return ;
	fill(stack_a, arr);
	median_sort(arr, ft_lstsize(*stack_a));
	rank(stack_a, arr);
	free (arr);
}

void	fill(t_list **stack, int *arr)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current)
	{
		arr[i] = current->content;
		++i;
		current = current->next;
	}
}

void	rank(t_list **stack, int *arr)
{
	int		i;
	t_list	*current;
	t_list	*start;

	i = 0;
	start = *stack;
	while (arr[i])
	{
		current = start;
		while (current)
		{
			if (current->num == arr[i])
			{
				current->content = i;
				break ;
			}
			else
				current = current->next;
		}
		++i;
	}
}
