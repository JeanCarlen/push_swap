/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:16:25 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/12 14:48:46 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, char letter)
{
	t_list	*new_head;
	t_list	*second_node;

	second_node = *stack_a;
	new_head = second_node->next;
	second_node->next = new_head->next;
	new_head->next = second_node;
	*stack_a = new_head;
	if (letter == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	sb(t_list **stack_b, char letter)
{
	sa(stack_b, letter);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	if (!stack_b)
		return ;
	*stack_b = temp_b->next;
	temp_b->next = *stack_a;
	*stack_a = temp_b;
	ft_putstr_fd("pa\n", 1);
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
	temp_a->next = *stack_b;
	*stack_b = temp_a;
	ft_putstr_fd("pb\n", 1);
}
