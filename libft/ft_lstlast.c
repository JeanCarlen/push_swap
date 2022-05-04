/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:49:19 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 16:35:42 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
