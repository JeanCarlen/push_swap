/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:16:00 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/05/04 10:56:54 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	check_if_sorted(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	len = (ac - 2);
	while (i < len)
	{
		if (av[i] > av[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_if_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < (ac - 2))
	{
		j = (i + 1);
		while (j < (ac - 1))
		{
			if (av[i] == av[j])
				return (0);
			j++;
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
