/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:21:26 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/19 15:48:50 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nbrs(t_list **stack_a, char tmp[4])
{
	t_list	*temp;
	int		a;
	int		b;

	temp = *stack_a;
	a = (int)temp->content;
	b = (int)temp->next->content;
	if (a > b)
		sa(stack_a, 'a', tmp);
}

void	three_nbrs(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	t_list	*temp;
	int		a;
	int		b;
	int		c;

	temp = *stack_a;
	a = (int)temp->content;
	b = (int)temp->next->content;
	c = (int)temp->next->next->content;
	if (a < b && b > c)
		rra(stack_a, 'a', tmp);
	if (a < b && b > c && c > a)
		sa(stack_a, 'a', tmp);
	if (a > b && b < c && a > c)
		ra(stack_a, stack_b, tmp);
	if (a > b && b > c)
	{
		ra(stack_a, stack_b, tmp);
		sa(stack_a, 'a', tmp);
	}
	if (a > b && b < c && a < c)
		sa(stack_a, 'a', tmp);
}

void	four_nbrs(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	t_list	*ptr_min;

	ptr_min = find_min(stack_a);
	if (check_sorted(stack_a))
		return ;
	while (*stack_a != ptr_min)
		ra(stack_a, stack_b, tmp);
	pb(stack_a, stack_b, tmp);
	three_nbrs(stack_a, stack_b, tmp);
	pa(stack_a, stack_b, tmp);
}

void	five_nbrs(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	t_list	*ptr_min;
	t_list	*current;
	int		i;

	ptr_min = find_min(stack_a);
	current = *stack_a;
	i = 0;
	if (check_sorted(stack_a))
		return ;
	while (current != ptr_min)
	{
		current = current->next;
		++i;
	}
	while (*stack_a != ptr_min)
	{
		if (i < 3)
			ra(stack_a, stack_b, tmp);
		else
			rra(stack_a, 'a', tmp);
	}
	pb(stack_a, stack_b, tmp);
	four_nbrs(stack_a, stack_b, tmp);
	pa(stack_a, stack_b, tmp);
}

void	choose_sort(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		two_nbrs(stack_a, tmp);
	if (size == 3)
		three_nbrs(stack_a, stack_b, tmp);
	if (size == 4)
		four_nbrs(stack_a, stack_b, tmp);
	if (size == 5)
		five_nbrs(stack_a, stack_b, tmp);
	if (size > 5)
		radix(stack_a, stack_b, tmp);
}
