/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:18:40 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 10:57:10 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<time.h>

int	main(int ac, char **av)
{
	int i;
	int nbr;

	srand(time(0));

	nbr = ft_atoi(av[1]);
	if (ac == 2)
	{
		printf("\"");
		for (i = 0; i < nbr; i++)
		{  
			printf ("%d ", rand());
		}
		printf("\"");
	}
	return (0);
}
