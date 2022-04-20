/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:58 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/20 15:51:59 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	if (!stack_b)
		return ;
	*stack_b = temp_b->next;
	if (*stack_b)
		temp_b->next->previous = NULL;
	temp_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = temp_b;
	*stack_a = temp_b;
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	if (!stack_a)
		return ;
	*stack_a = temp_a->next;
	if (*stack_b)
		temp_a->next->previous = NULL;
	temp_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = temp_a;
	*stack_b = temp_a;
	ft_putstr_fd("pb\n", 1);
}

void	sa(t_list **stack_a, char letter)
{
	t_list	*new_head;
	t_list	*second_node;

	second_node = *stack_a;
	new_head = second_node->next;
	new_head->previous = NULL;
	second_node->next = new_head->next;
	second_node->previous = new_head;
	new_head->next = second_node;
	*stack_a = new_head;
	check_last(stack_a);
	if (letter == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	sb(t_list **stack_b, char letter)
{
	sa(stack_b, letter);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 'a');
	sb(stack_b, 'b');
}

void	rra(t_list **stack_a, char letter)
{
	t_list	*head;
	t_list	*last;

	head = *stack_a;
	last = ft_lstlast(*stack_a);
	last->previous->next = NULL;
	head->previous = last;
	*stack_a = last;
	last->next = head;
	last->previous = NULL;
	check_last(stack_a);
	if (letter == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	rrb(t_list **stack_b, char letter)
{
	rra(stack_b, letter);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 'a');
	rrb(stack_b, 'b');
}

void	ra(t_list **stack_a, char letter)
{
	t_list	*temp;
	t_list	*last;
	t_list	*second;

	temp = *stack_a;
	last = ft_lstlast(*stack_a);
	second = temp->next;
	second->previous = NULL;
	last->next = temp;
	temp->previous = last;
	temp->next = NULL;
	*stack_a = second;
	check_last(stack_a);
	if (letter == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rb(t_list **stack_b, char letter)
{
	ra(stack_b, letter);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 'a');
	rb(stack_b, 'b');
}
