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
		{
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
		}
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

static int	find_median(int array[], int n);
static int	find_median_2(int array[], int n);

static int	find_median_2(int array[], int n)
{
	int	median;

	median = 0;
	if (n % 2 == 0)
		median = (array[(n - 1) / 2] + array[n / 2]) / 2.0;
	else
		median = array[n / 2];
	return (median);
}

static int	find_median(int array[], int n)
{
	int	i;
	int	median;

	i = 0;
	median = 0;
	median_sort(array, n);
	median = find_median_2(array, n);
	return (median);
}

int	median(t_list **stack_a)
{
	int		n;
	int		i;
	int		*array;
	t_list	*current;

	i = 0;
	n = ft_lstsize(*stack_a);
	current = *stack_a;
	array = malloc(sizeof(int) * n);
	if (!array)
		return (0);
	while (current)
	{
		array[i] = current->content;
		current = current->next;
		++i;
	}
	i = find_median(array, n);
	free(array);
	return (i);
}

t_list	*gimi_median(t_list **stack_a, int median)
{
	t_list	*median_ptr;
	t_list	*current;
	int		diff;

	current = *stack_a;
	diff = MAX_INT;
	while (current)
	{
		if (abs(current->content - median) < diff)
		{
			diff = abs(current->content - median);
			median_ptr = current;
		}
		current = current->next;
	}
	return (median_ptr);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	init_place(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	if (stack_a)
	{
		plc->top_a = *stack_a;
		plc->bot_a = ft_lstlast_solved(*stack_a);
	}
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

t_list	*find_max(t_list **stack)
{
	int		max;
	t_list	*ptr_max;
	t_list	*ptr;

	max = MIN_INT;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->content > max)
		{
			ptr_max = ptr;
			max = ptr->content;
		}
		ptr = ptr->next;
	}
	return (ptr_max);
}