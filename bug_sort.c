/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:58 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 16:34:29 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_place(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	plc->top_a = *stack_a;
	plc->bot_a = ft_lstlast_solved(*stack_a);
	if (stack_b)
	{
		plc->top_b = *stack_b;
		plc->bot_b = ft_lstlast(*stack_b);
	}
}

t_list	*compare(t_place *plc)
{
	t_list	*closest;
	int		diff;

	diff = MAX_INT;
	closest = NULL;
	if (plc->top_a->content - plc->top_b->content > 0 && plc->top_a->content - plc->top_b->content < diff)
	{
		diff = plc->top_a->content - plc->top_b->content;
		closest = plc->top_a;
	}
	if (plc->bot_a->content - plc->top_b->content > 0 && plc->bot_a->content - plc->top_b->content < diff)
	{
		diff = plc->bot_a->content - plc->top_b->content;
		closest = plc->bot_a;
	}
	if (plc->bot_b->content - plc->top_a->content > 0 && plc->bot_b->content - plc->top_a->content < diff)
	{
		diff = plc->bot_b->content - plc->top_a->content;
		closest = plc->top_a;
	}
	if (plc->bot_b->content - plc->bot_a->content > 0 && plc->bot_b->content - plc->bot_a->content < diff)
	{
		diff = plc->bot_b->content - plc->bot_a->content;
		closest = plc->bot_a;
	}
	plc->closest = closest;
	return (closest);
}

int	rotate_to(t_list **stack, t_list *ptr)
{
	int		size;
	int		i;
	t_list	*top;
	int		ra_tog;

	top = *stack;
	if (ptr == NULL)
		return (0);
	size = ft_lstsize(*stack);
	i = 0;
	ra_tog = 0;
	while (i <= size / 2 && top != ptr)
	{
		top = top->next;
		i++;
	}
	if (i <= size / 2)
		ra_tog = 1;
	while (*stack != ptr)
	{
		if (ra_tog)
			ra(stack, 'a');
		else
			rra(stack, 'a');
		++i;
	}
	return (1);
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