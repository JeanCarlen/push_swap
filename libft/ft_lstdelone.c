/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:49:59 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/16 15:24:50 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((void *)&lst->content);
	free(lst);
}
