/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:18:40 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/24 15:17:48 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	int nbr;
	unsigned int n = 100;

	srand(time(0));

	nbr = atoi(av[1]);
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
