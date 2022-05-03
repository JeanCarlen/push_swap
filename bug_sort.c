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
/*
void	jifas(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;

	int i = 0;


	plc = malloc(sizeof(t_place));
	if(!plc)
		return;
	plc->median = median(stack_a);
	init_place(stack_a, stack_b, plc);
	rotate_to(stack_a, gimi_median(stack_a, plc->median));
	pb(stack_a, stack_b);
	while(!check_sorted(stack_a) && !*stack_b)
	{
		init_place(stack_a, stack_b, plc);
		if ((!(plc->top_a->content < plc->bot_b->content)) && (!(plc->top_a->content > plc->top_b->content)))
		{
			sa(stack_a, 'a');
			init_place(stack_a, stack_b, plc);
		}
		rotate_to(stack_a, compare(plc));
		pb(stack_a, stack_b);
		init_place(stack_a, stack_b, plc);
		if (plc->top_b->content < plc->top_b->next->content)
			rb(stack_b, 'b');
//		print_lst(stack_a, stack_b);
	}
	free(plc);
}
*/
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
	plc->closest = closest;
	return (closest);
}

void	rotate_to(t_list **stack, t_list *ptr)
{
	int		size;
	int		i;
	t_list	*top;
	int		ra_tog;
	
	top = *stack;
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
	}
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