/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:58 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/04 14:55:44 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pusw *lst)
{
	if (lst->len_b >= 0)
	{
		lst->stack_a[++lst->len_a] = lst->stack_b[lst->len_b--];
		ps_putbuff(lst, "pa\n", 3);
	}
}

void	push_b(t_pusw *lst)
{
	if (lst->len_a >= 0)
	{
		lst->stack_b[++lst->len_b] = lst->stack_a[lst->len_a--];
		ps_putbuff(lst, "pb\n", 3);
	}
}

void	ps_putbuff(t_pusw *lst, char *str, char len)
{
	if ((lst->ps_count + len) > PS_BUFFSIZE)
	{
		write(1, lst->ps_buff, lst->ps_count);
		lst->ps_count = 0;
	}
	ft_memcpy(lst->ps_buff + lst->ps_count, str, len);
	lst->ps_count += len;
}
