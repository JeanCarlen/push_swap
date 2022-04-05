/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:14 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/04 14:55:49 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//fait 2 arrays de tailles similaire, l'une vide l'autre contenant l'av

static t_pusw	*ps_struct_init(int argc, char **argv)
{
	t_pusw	*lst;
	size_t	count;

	count = 0;
	lst = NULL;
	if (!(lst = (t_pusw*)malloc(sizeof(t_pusw))))
		ps_error(lst);
	ft_bzero(lst, sizeof(t_pusw));
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	while (--argc > 0)
		lst->stack_a[count++] = ft_atoi(argv[argc]);
	return (lst);
}




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
