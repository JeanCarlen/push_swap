/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:16 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/17 14:58:13 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current;
	while (next)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_error(t_list **stack_a, t_list **stack_b)
{
	free_all(stack_a, stack_b);
	write(2, "Error\n", 7);
	return (0);
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
			ft_putnbr_fd(current_a->num, 1);
			current_a = current_a->next;
		}
		write(1, "	", 1);
		if (current_b)
		{
			ft_putnbr_fd(current_b->num, 1);
			current_b = current_b->next;
		}
		write(1, "\n", 1);
	}
}

int	set_up_list(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	if (ac >= 3)
	{
		if (!check_if_digit(ac, &av[1]))
		{
			write(1, "digit ", 6);
			return (ft_error(stack_a, NULL));
		}
		set_up_av(ac, av, stack_a, stack_b);
	}
	if (ac == 2)
		if (!c_to_i(av[1], stack_a))
			return (0);
	if (!check_dup(stack_a))
	{
		write(1, "dup ", 4);
		return (ft_error(stack_a, NULL));
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!set_up_list(ac, av, &stack_a, &stack_b))
		return (0);
	choose_sort(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b);
	return (0);
}
