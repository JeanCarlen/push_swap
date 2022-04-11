/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/08 15:20:49 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_up(int ac, int *num, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i <= (ac - 2))
		ft_lstadd_back(stack_a, ft_lstnew(&num[i++]));
	if (check_if_sorted(ac, num))
		return (0);
	if (ac == 3)
		ft_two_nbrs(stack_a);
	if (ac == 4)
		ft_three_nbrs(stack_a);
	if (ac > 4 && ac <= 6)
		ft_five_nbrs(stack_a, stack_b);
	if (ac > 6)
		ft_big_sort(stack_a, stack_b);
	return (0);
}

int	ft_error(int *num, t_list **a)
{
	free(num);
	ft_lstclear(a, del);
	return (write(2, "Error\n", 7));
}

unsigned int	ft_check_isdigit(int ac, char **av)
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