/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:08 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/14 13:57:52 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nbrs(t_list **stack_a)
{
	t_list	*temp;
	int		a;
	int		b;

	printf("start sort 2\n");
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

	printf("start sort 3\n");
	temp = *stack_a;
	a = (int)temp->content;
	b = (int)temp->next->content;
	c = (int)temp->next->next->content;
	printf("content ok \n");
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
	printf("sort done \n");
}
int		big_sort(void);//sort la stack si find_length est + que 5

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
	printf("size is %d\n", size);
	if (size == 2)
		two_nbrs(stack_a);
	printf("2 ok\n");
	if (size == 3)
		three_nbrs(stack_a);
}

void	c_to_i(char	*str, t_list **stack_a)
{
	int		i;
	int		j;
	int		n;
	char	**nbr;

	i = 0;
	nbr = ft_split(str, ' ');
	while (nbr[i])
	{
		n = ft_atoi(nbr[i]);
		ft_lstadd_back(stack_a, ft_lstnew((void *)n));
		free(nbr[i]);
		++i;
	}
}
