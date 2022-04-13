/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/13 16:30:31 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_list **a)
{
//	ft_lstclear(a, del);
	return (write(2, "Error\n", 7));
}

int	check_if_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
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

void	check_last(t_list **last)
{
	t_list	*temp;

	temp = *last;
	while (temp->next)
	{
		temp->next->previous = temp;
		temp = temp->next;
	}
}

void	print_lst(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}
