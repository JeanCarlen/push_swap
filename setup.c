/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:17:35 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/12 15:08:11 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	l_no_spc(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == ' ')
		++i;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			++count;
		++i;
	}
	if (str[i - 1] == ' ')
		count--;
	return (count + 1);
}

int	c_to_i(char	*str, t_list **stack_a)
{
	int		i;
	int		n;
	int		size;
	char	**nbr;

	i = 0;
	size = l_no_spc(str);
	nbr = ft_split(str, ' ');
	if (check_if_digit(size + 1, nbr) == 0)
	{
		write(1, "digit ", 6);
		return (ft_error(stack_a, NULL));
	}
	while (nbr[i])
	{
		n = ft_atoi(nbr[i]);
		ft_lstadd_back(stack_a, ft_lstnew(n));
		free(nbr[i]);
		++i;
	}
	return (1);
}

int	set_up_av(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	nbr;

	i = 1;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		ft_lstadd_back(stack_a, ft_lstnew(nbr));
		++i;
	}
	return (0);
}
