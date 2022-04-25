/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:18:40 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/25 15:16:24 by jeancarlen       ###   ########.fr       */
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
