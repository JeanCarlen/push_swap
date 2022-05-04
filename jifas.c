/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jifas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:04:43 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/04 16:34:34 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jifas(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;
	int i=0;

	plc = malloc(sizeof(t_place));
	if (!plc)
		return ;
	plc->median = median(stack_a);
	init_place(stack_a, stack_b, plc);
	rotate_to(stack_a, gimi_median(stack_a, plc->median));
	pb(stack_a, stack_b);
	while (!check_sorted(stack_a) || is_empty(*stack_b) == 0)
	{
		init_place(stack_a, stack_b, plc);
		if ((!(plc->top_a->content < plc->bot_b->content)) && (!(plc->top_a->content > plc->top_b->content)) && (plc->top_a->next->solved == 0))
		{
			sa(stack_a, 'a');
			init_place(stack_a, stack_b, plc);
		}
		if (rotate_to(stack_a, compare(plc)))
			pb(stack_a, stack_b);
		init_place(stack_a, stack_b, plc);
		if (plc->top_b->content < plc->top_b->next->content)
			rb(stack_b, 'b');
		if (check_sorted(stack_a) && reverse_sorted(stack_b) && check_solved(stack_a))
		{
			while (is_empty(*stack_b) == 0)
			{
				rrb(stack_b, 'b');
				pa(stack_a, stack_b);
				ra(stack_a, 'a');
			}
			return ;
		}
		while ((*stack_a)->solved == 1 && !check_sorted(stack_a) && i < 7)
		{
			ra(stack_a, 'a');
			// printf("viens ici sale encule2\n");
			// print_lst(stack_a, stack_b);
			++i;
		}
		init_place(stack_a, stack_b, plc);
		if (is_empty(*stack_a) == 1)
		{
			while (is_empty(*stack_b) == 0)
				pa(stack_a, stack_b);
		}
		if (!is_empty(*stack_b))
			solver(stack_a, stack_b, plc);
		// print_lst(stack_a, stack_b);
	}
	free(plc);
}

int	solver(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	int	min;

	min = find_min(stack_a)->content;
	init_place(stack_a, stack_b, plc);
	if (plc->top_a->content < plc->top_b->content && plc->top_a->content > plc->bot_b->content 
		&& plc->bot_a->content < plc->top_b->content && plc->bot_a->content > plc->bot_b->content)
	{
		while (plc->bot_b->content < min)
		{
			rrb(stack_b, 'b');
			pa(stack_a, stack_b);
			ra(stack_a, 'a');
			if (plc->bot_b->content < plc->bot_a->content)
				plc->bot_b->solved = 1;
			plc->bot_b = ft_lstlast_solved(*stack_b);
		}
	}
	return (0);
}

int	is_empty(t_list *list)
{
	if (!list)
		return (1);
	return (0);
}

void	rotate_to_b(t_list **stack, t_list *ptr)
{
	int		size;
	int		i;
	t_list	*top;
	int		rb_tog;

	top = *stack;
	size = ft_lstsize(*stack);
	i = 0;
	rb_tog = 0;
	while (i <= size / 2 && top != ptr)
	{
		top = top->next;
		i++;
	}
	if (i <= size / 2)
		rb_tog = 1;
	while (*stack != ptr)
	{
		if (rb_tog)
			rb(stack, 'b');
		else
			rrb(stack, 'b');
	}
}

t_list	*ft_lstlast_solved(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL || lst->next->solved == 1)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	reverse_sorted(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!*stack)
		return (0);
	ptr1 = *stack;
	ptr2 = ptr1->next;
	while (ptr2)
	{
		if (ptr1->content < ptr2->content)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr1->next;
	}
	return (1);
}

int	check_solved(t_list **stack)
{
	t_list	*ptr1;

	if (!*stack)
		return (0);
	ptr1 = *stack;
	while (ptr1)
	{
		if (ptr1->solved == 0)
			return (0);
		ptr1 = ptr1->next;
	}
	return (1);
}