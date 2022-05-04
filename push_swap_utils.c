/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 16:34:36 by fmalizia         ###   ########.ch       */
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

void	print_lst(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	while (current_a != NULL || current_b != NULL)
	{	
		if (current_a)
		{
			// ft_putnbr_fd(current_a->num, 1);
			if (current_a->solved)
				printf("\033[32;1m %d\033[0m", current_a->content);
			else
				printf("\033[32;2m %d\033[0m", current_a->content);
			current_a = current_a->next;
		}
		printf("	");
		//write(1, "	", 1);
		if (current_b)
		{
			// ft_putnbr_fd(current_b->num, 1);
			printf("%d", current_b->content);
			current_b = current_b->next;
		}
		printf("\n");
		//write(1, "\n", 1);
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
