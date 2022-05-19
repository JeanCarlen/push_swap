/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:16:25 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/19 15:51:28 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, char letter, char tmp[4])
{
	t_list	*new_head;
	t_list	*second_node;

	second_node = *stack_a;
	new_head = second_node->next;
	second_node->next = new_head->next;
	new_head->next = second_node;
	*stack_a = new_head;
	if (letter == 'a')
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "sa", 3);
	}
	else
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "sb", 3);
	}
}

void	sb(t_list **stack_b, char letter, char tmp[4])
{
	sa(stack_b, letter, tmp);
}

void	pa(t_list **stack_a, t_list **stack_b, char tmp[4])
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
	if (ft_strncmp(tmp, "pb", 3))
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "pa", 3);
	}
	else
		ft_bzero(tmp, 3);
}

void	pb(t_list **stack_a, t_list **stack_b, char tmp[4])
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
	if (ft_strncmp(tmp, "pa", 3))
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "pb", 3);
	}
	else
		ft_bzero(tmp, 3);
}
