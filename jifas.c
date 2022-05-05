/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jifas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:04:43 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/05 11:5:49 by marvin           ###   ########.fr       */
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
		init_place(stack_a, stack_b, plc);
		if (*stack_a)
		{
			while ((*stack_a)->solved == 1 && !check_sorted(stack_a) && !check_solved(stack_a))
			{
				ra(stack_a, 'a');
			}
			while(ft_lstlast(*stack_a)->solved == 0 && check_one_solved(stack_a))
			{
				rra(stack_a, 'a');
			}
		}
		init_place(stack_a, stack_b, plc);
		if (is_empty(*stack_a) == 1)
		{
			while (is_empty(*stack_b) == 0)
				pa(stack_a, stack_b);
		}
		if (!is_empty(*stack_b))
			if(!solver(stack_a, stack_b, plc))
			{
				rotate_to(stack_a, find_min(stack_a));
				pb(stack_a, stack_b);
				rb(stack_b, 'b');
				while ((*stack_a)->solved == 1 && !check_sorted(stack_a))
				{
					ra(stack_a, 'a');
				}
				while(ft_lstlast(*stack_a)->solved == 0 && check_one_solved(stack_a))
				{
					rra(stack_a, 'a');
				}	
			}
//		print_lst(stack_a, stack_b);
	}
	free(plc);
}

int	solver(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	int	min;
	int	push;

	push = 0;
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
			plc->bot_b->solved = 1;
			plc->bot_b = ft_lstlast(*stack_b);
			++push;
		}
	}
	else
		++push;
	return (push);
}

int	is_empty(t_list *list)
{
	if (!list)
		return (1);
	return (0);
}

int	rotate_to(t_list **stack, t_list *ptr)
{
	int		size;
	int		i;
	t_list	*top;
	int		ra_tog;

	top = *stack;
	if (ptr == NULL || !*stack)
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
		{
			rra(stack, 'a');
		}
		++i;
	}
	return (1);
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

int	check_one_solved(t_list **stack)
{
	t_list	*ptr1;

	if (!*stack)
		return (0);
	ptr1 = *stack;
	while (ptr1)
	{
		if (ptr1->solved == 1)
			return (1);
		ptr1 = ptr1->next;
	}
	return (0);
}