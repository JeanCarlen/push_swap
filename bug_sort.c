/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:58 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 10:56:36 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
*/
/* gerer les 7premier bit, puis le neg sur le 8

*/
/*
void	jifas(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;

	int i = 0;


	plc = malloc(sizeof(t_place));
	if (!plc)
		return ;
	plc->median = median(stack_a);
	init_place(stack_a, stack_b, plc);
	rotate_to(stack_a, gimi_median(stack_a, plc->median));
	pb(stack_a, stack_b);
	while (!check_sorted(stack_a))
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
void	init_place(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	plc->top_a = *stack_a;
	plc->bot_a = ft_lstlast(*stack_a);
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

	diff = plc->top_a->content - plc->top_b->content;
	closest = plc->top_a;
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