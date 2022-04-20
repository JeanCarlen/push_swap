/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:16:00 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/04/20 15:52:00 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	check_if_sorted(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	len = (ac - 2);
	while (i < len)
	{
		if (av[i] > av[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_if_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < (ac - 2))
	{
		j = (i + 1);
		while (j < (ac - 1))
		{
			if (av[i] == av[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
