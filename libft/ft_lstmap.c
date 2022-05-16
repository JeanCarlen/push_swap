/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:50:35 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/16 15:25:41 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*save;

	if (!lst)
		return (0);
	newlist = ft_lstnew((int)f((void *)&lst->content));
	if (!newlist)
		return (0);
	save = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist->next = ft_lstnew((int)f((void *)&lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	newlist->next = NULL;
	return (save);
}
