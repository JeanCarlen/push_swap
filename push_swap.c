/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:16 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/21 11:52:82:17 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_up_av(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	nbr;

	i = 1;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		ft_lstadd_back(stack_a, ft_lstnew(nbr));
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 3)
	{
		if (!check_if_digit(ac, &av[1]))
		{
			write(1, "digit ", 6);
			return (ft_error(&stack_a));
		}
		set_up_av(ac, av, &stack_a, &stack_b);
	}
	if (ac == 2)
		if (!c_to_i(av[1], &stack_a))
			return (0);
	if (!check_dup(&stack_a))
	{
		write(1, "dup ", 4);
		return (ft_error(&stack_a));
	}
	set_previous(&stack_a);
	choose_sort(&stack_a, &stack_b);
//	ft_lstclear(stack_a, del);
//	write(1, "Stack a\n", 8);
//	tester(&stack_a, &stack_b);
	printf("stack_a =\n");
	print_lst(&stack_a, &stack_b);
	return (0);
}
