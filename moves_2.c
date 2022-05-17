/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:18:38 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/17 14:58:11 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, char letter)
{
	t_list	*temp;
	t_list	*last;
	t_list	*second;

	if (!*stack_a)
		return ;
	if (!(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = ft_lstlast(*stack_a);
	second = temp->next;
	last->next = temp;
	temp->next = NULL;
	*stack_a = second;
	if (letter == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rb(t_list **stack_b, char letter)
{
	ra(stack_b, letter);
}

void	rra(t_list **stack_a, char letter)
{
	t_list	*head;
	t_list	*last;
	t_list	*current;

	head = *stack_a;
	current = *stack_a;
	if ((*stack_a)->next == NULL)
		return ;
	last = ft_lstlast(*stack_a);
	while(current->next != last)
		current = current->next;
	current->next = NULL;
	*stack_a = last;
	last->next = head;
	if (letter == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	rrb(t_list **stack_b, char letter)
{
	rra(stack_b, letter);
}
