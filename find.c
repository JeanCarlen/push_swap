/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:22:54 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/04 10:57:17 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_median(int array[], int n);
static int	find_median_2(int array[], int n);

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

static int	find_median_2(int array[], int n)
{
	int	median;

	median = 0;
	if (n % 2 == 0)
		median = (array[(n - 1) / 2] + array[n / 2]) / 2.0;
	else
		median = array[n / 2];
	return (median);
}

static int	find_median(int array[], int n)
{
	int	i;
	int	median;

	i = 0;
	median = 0;
	median_sort(array, n);
	median = find_median_2(array, n);
	return (median);
}

int	median(t_list **stack_a)
{
	int		n;
	int		i;
	int		*array;
	t_list	*current;

	i = 0;
	n = ft_lstsize(*stack_a);
	current = *stack_a;
	array = malloc(sizeof(int) * n);
	if (!array)
		return (0);
	while (current)
	{
		array[i] = current->content;
		current = current->next;
		++i;
	}
	i = find_median(array, n);
	free(array);
	return (i);
}

t_list	*gimi_median(t_list **stack_a, int median)
{
	t_list	*median_ptr;
	t_list	*current;
	int		diff;

	current = *stack_a;
	diff = MAX_INT;
	while (current)
	{
		if (abs(current->content - median) < diff)
		{
			diff = abs(current->content - median);
			median_ptr = current;
		}
		current = current->next;
	}
	return (median_ptr);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
