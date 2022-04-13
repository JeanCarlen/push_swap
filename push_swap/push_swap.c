/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:16 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/12 13:56:23 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_up(int args, int *num, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i <= (args - 2))
		ft_lstadd_back(stack_a, ft_lstnew(&num[i++]));
	if (check_if_sorted(args, num))
		return (0);
	if (args == 3)
		two_nbrs(stack_a);
	if (args == 4)
		three_nbrs(stack_a);
	if (args > 4 && args <= 6)
		five_nbrs(stack_a, stack_b);
	if (args > 6)
		big_sort(stack_a, stack_b);
	return (0);
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
		return (write(2, "Error\n", 7));
	if (ac >= 3)
	{
		if (!check_if_digit(ac, av))
			return (ft_error(num, &stack_a));
		if (!check_if_dup(ac, num))
			return (ft_error(num, &stack_a));
		set_up(ac, num, &stack_a, &stack_b);
	}
	free(num);
	ft_lstclear(&stack_a, del);
	return (0);
}

