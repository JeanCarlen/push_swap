/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:08 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/05 15:19:29 by marvin               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nbrs(t_list **stack_a)
{
	t_list	*temp;
	int		a;
	int		b;

	temp = *stack_a;
	a = (int)temp->content;
	b = (int)temp->next->content;
	if (a > b)
		sa(stack_a, 'a');
}

void	three_nbrs(t_list **stack_a)
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
		rra(stack_a, 'a');
	if (a < b && b > c && c > a)
		sa(stack_a, 'a');
	if (a > b && b < c && a > c)
		ra(stack_a, 'a');
	if (a > b && b > c)
	{
		ra(stack_a, 'a');
		sa(stack_a, 'a');
	}
	if (a > b && b < c && a < c)
		sa(stack_a, 'a');
}

void	four_nbrs(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr_min;

	ptr_min = find_min(stack_a);
	if (check_sorted(stack_a))
		return ;
	while (*stack_a != ptr_min)
		ra(stack_a, 'a');
	pb(stack_a, stack_b);
	three_nbrs(stack_a);
	pa(stack_a, stack_b);
}

void	five_nbrs(t_list **stack_a, t_list **stack_b)
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
			ra(stack_a, 'a');
		else
			rra(stack_a, 'a');
	}
	pb(stack_a, stack_b);
	four_nbrs(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	l_no_spc(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == ' ')
		++i;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			++count;
		++i;
	}
	if (str[i - 1] == ' ')
		count--;
	return (count + 1);
}

void	choose_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		two_nbrs(stack_a);
	if (size == 3)
		three_nbrs(stack_a);
	if (size == 4)
		four_nbrs(stack_a, stack_b);
	if (size == 5)
		five_nbrs(stack_a, stack_b);
	if (size > 5)
		big_sort(stack_a, stack_b);
}

int	c_to_i(char	*str, t_list **stack_a)
{
	int		i;
	int		n;
	int		size;
	char	**nbr;

	i = 0;
	size = l_no_spc(str);
	nbr = ft_split(str, ' ');
	if (check_if_digit(size + 1, nbr) == 0)
	{
		write(1, "digit ", 6);
		return (ft_error(stack_a));
	}
	while (nbr[i])
	{
		n = ft_atoi(nbr[i]);
		ft_lstadd_back(stack_a, ft_lstnew(n));
		free(nbr[i]);
		++i;
	}
	return (1);
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

t_list	*find_min(t_list **stack)
{
	int		min;
	t_list	*ptr_min;
	t_list	*ptr;

	min = MAX_INT;
	ptr = *stack;
	ptr_min = *stack;
	if (!*stack)
		return (NULL);
	while (ptr)
	{
		if (ptr->content < min && ptr->solved == 0)
		{
			ptr_min = ptr;
			min = ptr->content;
		}
		ptr = ptr->next;
	}
	return (ptr_min);
}
