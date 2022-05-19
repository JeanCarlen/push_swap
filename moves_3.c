/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:21:17 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/18 16:26:3 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	ra(stack_a, stack_b, tmp);
	rb(stack_a, stack_b, tmp);
}

void	ss(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	sa(stack_a, 'a', tmp);
	sb(stack_b, 'b', tmp);
}

void	rrr(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	rra(stack_a, 'a', tmp);
	rrb(stack_b, 'b', tmp);
}
