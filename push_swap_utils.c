/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/21 14:12:22 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_list **a)
{
//	ft_lstclear(a, del);
	write(2, "Error\n", 7);
	return (0);
}

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
		ft_putnbr_fd(current->content, 1);
		write(1, "\n", 1);
		current = current->next;
	}
}

void	set_previous(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	ptr2 = ptr1->next;
	while (ptr2->next)
	{
		ptr2 = ptr1->next;
		ptr2->previous = ptr1;
		ptr1 = ptr1->next;
	}
}
