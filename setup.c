/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:17:35 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/24 15:14:03 by jcarlen          ###   ########.ch       */
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
	long	n;
	char	**nbr;

	i = -1;
	nbr = ft_split(str, ' ');
	if (check_if_digit(l_no_spc(str) + 1, nbr) == 0)
	{
		write(1, "digit ", 6);
		return (ft_error(stack_a));
	}
	while (nbr[++i])
	{
		n = ft_atol(nbr[i]);
		if (n > MAX_INT)
		{
			write(1, "over max int ", 13);
			return (ft_error(stack_a));
		}
		ft_lstadd_back(stack_a, ft_lstnew(n));
		free(nbr[i]);
	}
	free(nbr[i]);
	return (1);
}

int	set_up_av(char **av, t_list **stack_a)
{
	int		i;
	long	nbr;

	i = 1;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr > MAX_INT)
		{
			write(1, "over max int ", 13);
			return (ft_error(stack_a));
		}
		ft_lstadd_back(stack_a, ft_lstnew(nbr));
		++i;
	}
	return (1);
}
