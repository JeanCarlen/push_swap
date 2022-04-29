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

	plc->median = median(stack_a);
	init_place(stack_a, stack_b, plc);
	while()
	{
		pb(stack_a, stack_b);
		if (plc->top_a->content < plc->top_a->next->content)
			sa(stack_a, 'a');

	}


}

void init_place(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	plc->top_a = *stack_a;
	plc->bot_a = ft_lstlast(*stack_a);
	if(stack_b)
	{
		plc->top_b = *stack_b;
		plc->bot_b = ft_lstlast(*stack_b);
	}
}

t_list	*compare(t_place *plc)
{
	t_list	*closest;
	
	int		diff;

	diff = plc->top_a->content - plc->top_b->content;
	closest = plc->top_a;
	if (plc->bot_a->content - plc->top_b->content > 0 && plc->bot_a->content - plc->top_b->content < diff)
	{
		diff = plc->bot_a->content - plc->top_b->content;
		closest = plc->bot_a;
	}
	if (plc->bot_b->content - plc->top_a->content > 0 && plc->bot_b->content -plc->top_a->content < diff)
	{
		diff = plc->bot_b->content - plc->top_a->content;
		closest = plc->top_a;
	}
	if (plc->bot_b->content - plc->bot_a->content > 0 && plc->bot_b->content -plc->bot_a->content < diff)
	{
		diff = plc->bot_b->content - plc->bot_a->content;
		closest = plc->bot_a;
	}
	return (closest);
}
/*
void tester(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;
	t_list	*closest;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	init_place(stack_a, stack_b, plc);
	closest = compare(plc);
	printf("closest:%d\n", closest->content);
}
*/