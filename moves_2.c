/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:18:38 by fmalizia          #+#    #+#             */
/*   Updated: 2022/05/18 100:00:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, t_list **stack_b, char tmp[4])
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
	if (!ft_strncmp(tmp, "rb", 3))
	{
		ft_strlcpy(tmp, "rr", 3);
	}
	else
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
		write(1, "\n", 1);
		ft_strlcpy(tmp, "ra", 3);
	}
}

void	rb(t_list **stack_a, t_list **stack_b, char tmp[4])
{
	t_list	*temp;
	t_list	*last;
	t_list	*second;

	if (!*stack_b)
		return ;
	if (!(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = ft_lstlast(*stack_b);
	second = temp->next;
	last->next = temp;
	temp->next = NULL;
	*stack_b = second;
	if (!ft_strncmp(tmp, "ra", 3))
		ft_strlcpy(tmp, "rr", 3);
	else
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "rb", 3);
	}
}

void	rra(t_list **stack_a, char letter, char tmp[4])
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
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "rra", 4);
	}
	else
	{
		ft_putstr_fd(tmp, 1);
		if (*tmp)
			write(1, "\n", 1);
		ft_strlcpy(tmp, "rrb", 4);
	}
}

void	rrb(t_list **stack_b, char letter, char tmp[4])
{
	rra(stack_b, letter, tmp);
}
