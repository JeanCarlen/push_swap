/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:03:04 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/05 15:51:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		bit;
	int		i;
	int		size;

	bit = 0;
	ft_range(stack_a);
	size = ft_lstsize(*stack_a);
	while (!check_sorted(stack_a))
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->content >> bit) & 1) == 1)
				ra(stack_a, 'a');
			else
				pb(stack_a, stack_b);
			++i;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
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
