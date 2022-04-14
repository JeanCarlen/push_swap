/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:16 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/14 15:36:22 by fmalizia         ###   ########.ch       */
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
		ft_lstadd_back(stack_a, ft_lstnew((void *)nbr));
		++i;
	}
	if (!check_if_sorted(ac, av))
		return (0);
	/*if (ac > 4 && ac <= 6)
		five_nbrs(stack_a, stack_b);
	if (ac > 6)
		big_sort(stack_a, stack_b);*/
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
		if (!check_if_digit(ac, av))
			return (ft_error(&stack_a));
		if (!check_if_dup(ac, av))
			return (ft_error(&stack_a));
		set_up_av(ac, av, &stack_a, &stack_b);
	}
	if (ac == 2)
		c_to_i(av[1], &stack_a);
	printf("list made\n");
	choose_sort(&stack_a, &stack_b);
	//ft_lstclear(stack_a, del);
	print_lst(&stack_a);
	return (0);
}
