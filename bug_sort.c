/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:58 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/25 16:21:392 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void big_sort(t_list **stack_a, t_list **stack_b)
{
	int		bit;
	int		max;
	t_list	*ptr;
	t_list	*start;
	
	bit = 0;
	start = NULL;
	while(bit <= 8)
	{
		while(*stack_a != start && *stack_a)
		{
			ptr = *stack_a;
			if (ptr->content >> bit & 1)
				pb(stack_a, stack_b);
			else if (!start)
				start = *stack_a;
			ra(stack_a, 'a');
		}
		//print_lst(stack_b);
		start = NULL;
		while(*stack_b)
		{
			pa(stack_a, stack_b);
		}
		bit++;
	}
}
/* gerer les 7premier bit, puis le neg sur le 8

*/
