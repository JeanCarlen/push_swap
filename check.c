/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:15:56 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/12 14:53:13 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && av[i][j + 1])
			{
				if (!ft_isdigit(av[i][j + 1]))
					return (0);
				j += 2;
			}
			else
			{
				if (!ft_isdigit(av[i][j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_sorted(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!*stack)
		return (0);
	ptr1 = *stack;
	ptr2 = ptr1->next;
	while (ptr2)
	{
		if (ptr1->content > ptr2->content)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr1->next;
	}
	return (1);
}

int	check_dup(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->content == ptr2->content)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

t_list	*find_min(t_list **stack)
{
	int		min;
	t_list	*ptr_min;
	t_list	*ptr;

	min = MAX_INT;
	ptr = *stack;
	ptr_min = *stack;
	if (!*stack)
		return (NULL);
	while (ptr)
	{
		if (ptr->content < min && ptr->solved == 0)
		{
			ptr_min = ptr;
			min = ptr->content;
		}
		ptr = ptr->next;
	}
	return (ptr_min);
}
