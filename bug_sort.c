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

typedef struct s_place
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*bot_a;
	t_list	*bot_b;
	t_list	*min_b;
	t_list	*max_a;
	t_list	*start;
}					t_place;


void big_sort(t_list **stack_a, t_list **stack_b)
{
	int		bit;
	int		max;
	t_list	*ptr;
	t_list	*start;

	bit = 0;
	start = NULL;
	while (bit <= 8)
	{
		while (*stack_a != start && *stack_a)
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
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
		bit++;
	}
}
/* gerer les 7premier bit, puis le neg sur le 8

*/

void	jifas(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;

	init_place(stack_a, stack_b, plc);
}

void init_place(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	plc->top_a = *stack_a;
	plc->bot_a = ft_lstlast(stack_a);
	plc->top_a = *stack_b;
	plc->bot_a = ft_lstlast(stack_b);
}

void compare(t_list **stack_a, t_list **stack_b)
{

}

void	find_median(t_list **stack_a)
{

}