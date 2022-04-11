/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:16:00 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/04/08 15:20:10 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int check_if_sorted(int ac, int *num)
{
	int	i;
	int	len;

	i = 0;
	len = (ac - 2);
	while (i < len)
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int check_if_dup(int args, int *num)
{
	int	i;
	int	j;

	i = 0;
	while (i < (args - 2))
	{
		j = (i + 1);
		while (j < (args - 1))
		{
			if (num[i] == num[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}