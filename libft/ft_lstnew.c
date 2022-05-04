/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:01:37 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 16:35:46 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content);

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->num = content;
	new->next = NULL;
	new->solved = 0;
	return (new);
}
