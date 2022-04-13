/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:08 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/13 16:30:26 by jcarlen          ###   ########.fr       */
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
		ra(stack_a, 'a');
	}
	if (a > b && b < c && a < c)
		sa(stack_a, 'a');
}
int		big_sort();//sort la stack si find_length est + que 5

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

void	c_to_i(char	*str, t_list **stack_a)
{
	int		i;
	int		j;
	char	**nbr;

	i = 0;
	nbr = ft_split(str, ' ');
	while (nbr[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(nbr[i])));
		free(nbr[i]);
		++i;
	}
}
