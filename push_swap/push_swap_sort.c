/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:08 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/12 15:11:25 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nbrs(t_list **stack_a)
{
	t_list	*temp;
	int		one;
	int		two;

	temp = *stack_a;
	first = *((int *)temp->content);
	second = *((int *)temp->next->content);
	if (first > second)
		ft_sa(stack_a, 'a');
}
/*void    three_nbrs(t_list **stack_a)
{
    t_list  *temp;
    int     first;
    int     second;
    int     third;

    temp = *stack_a;
	first = *((int *)temp->content);
	second = *((int *)temp->next->content);
    third = *((int *)temp->next->next->content);
    if()
}
int		big_sort();//sort la stack si find_length est + que 5*/
