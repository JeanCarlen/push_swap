/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:18:40 by jcarlen           #+#    #+#             */
/*   Updated: 2022/03/31 15:02:21 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  
#include <stdlib.h>

int	main()
{
	int i, num;
	for (i = 1; i <= 10; i++)
	{  
		num = rand() % 300 + 1;
		printf (" %d\n", num);
	}
	return (0);
}