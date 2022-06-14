/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:09:37 by jcarlen           #+#    #+#             */
/*   Updated: 2022/06/14 13:56:28 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	int		bit;

	bit = 0;
	ft_range(stack_a);
	while (!check_sorted(stack_a))
	{
		radix_1(stack_a, stack_b, tmp, bit);
		bit++;
		if (!check_sorted(stack_a) || !reverse_sorted(stack_b))
			radix_2(stack_a, stack_b, tmp, bit);
		else
			while (*stack_b)
				pa(stack_a, stack_b, tmp);
	}
}

void	radix_1(t_list **stack_a, t_list **stack_b, char tmp[4], int bit)
{
	int		i;
	int		size_a;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	while (i < size_a)
	{
		if ((((*stack_a)->content >> bit) & 1) == 1)
			ra(stack_a, stack_b, tmp);
		else
			pb(stack_a, stack_b, tmp);
		++i;
	}
}

void	radix_2(t_list **stack_a, t_list **stack_b, char tmp[4], int bit)
{
	int	i;
	int	size_b;

	i = 0;
	size_b = ft_lstsize(*stack_b);
	while (i < size_b)
	{
		if ((((*stack_b)->content >> bit) & 1) != 1)
			rb(stack_a, stack_b, tmp);
		else
			pa(stack_a, stack_b, tmp);
		++i;
	}
}
