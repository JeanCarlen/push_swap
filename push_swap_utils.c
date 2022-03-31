/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/03/31 15:02:20 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <stdio.h>

//fait 2 arrays de tailles similaire, l'une vide l'autre contenant l'av
/*
int init(char **av)
{
	int i;

	while(av[i])
	{
		if(av[i+1] == ' ')
		*ft_lstnew()
	}
}
*/

int	find_length(int ac, char **av)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!j || av[i][j - 1] == ' ') && av[i][j] != ' ')
				length++;
			j++;
		}
		i++;
	}
	return (length - 1);
}

int main(int ac, char **av)
{
	printf("%d\n", find_length(ac, av));
	return (0);
}
