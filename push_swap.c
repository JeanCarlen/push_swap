/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:16 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/13 16:30:09 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_up_av(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int size;

	i = 1;
	while (av[i])
	{
		while (av[i])
		{
			ft_lstadd_back(stack_a, ft_lstnew((void *)ft_atoi(av[i])));
			++i;
		}
	}
	if (!check_if_sorted(ac, av))
		return (0);
	size = ft_lstsize(*stack_a);
	if (size == 2)
		two_nbrs(stack_a);
	if (size == 3)
		three_nbrs(stack_a);
	/*if (ac > 4 && ac <= 6)
		five_nbrs(stack_a, stack_b);
	if (ac > 6)
		big_sort(stack_a, stack_b);*/
	return (0);
}

void	set_up_str(t_list **stack_a, char **av)
{
	int	size;

	size = 0;
	c_to_i(av[1], stack_a);
	size = ft_lstsize(*stack_a);
	if (size == 2)
		two_nbrs(stack_a);
	if (size == 3)
		three_nbrs(stack_a);
}

int	main(int ac, char **av)
{
	int		*num;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	num = NULL;
	num = malloc(((ac - 1) * sizeof(int)));
	if (!num)
		return (write(2, "Malloc error\n", 13));
	if (ac >= 3)
	{
		if (!check_if_digit(ac, av))
			return (ft_error(&stack_a));
		if (!check_if_dup(ac, av))
			return (ft_error(&stack_a));
		set_up_av(ac, av, &stack_a, &stack_b);
	}
	if (ac == 2)
		set_up_str(&stack_a, av);
	//ft_lstclear(stack_a, del);
	print_lst(&stack_a);
	free(num);
	return (0);
}
