/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:03:04 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/03 17:03:28 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		bit;
	int		i;
	int		size;

	bit = 0;
	size = ft_lstsize(*stack_a);
	while (!check_sorted(stack_a))
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->content >> bit) & 1) == 1)
				ra(stack_a, 'a');
			else
				pb(stack_a, stack_b);
			++i;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}
