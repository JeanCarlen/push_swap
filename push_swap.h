/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:25 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/19 16:41:01 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647

/* push_swap */
int		main(int ac, char **av);
int		set_up_list(int ac, char **av, t_list **stack_a);
void	free_all(t_list **stack_a);
int		ft_error(t_list **stack_a);
void	print_lst(t_list **stack_a, t_list **stack_b);

/* moves_1 */
void	sa(t_list **stack_a, char letter, char tmp[4]);
void	sb(t_list **stack_b, char letter, char tmp[4]);
void	pa(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	pb(t_list **stack_a, t_list **stack_b, char tmp[4]);

/* moves_2 */
void	ra(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	rb(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	rra(t_list **stack_a, char letter, char tmp[4]);
void	rra_1(char letter, char tmp[4]);
void	rrb(t_list **stack_b, char letter, char tmp[4]);

/* moves_3 */
void	rr(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	ss(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	rrr(t_list **stack_a, t_list **stack_b, char tmp[4]);

/* check */
int		check_if_digit(int ac, char **av);
int		check_sorted(t_list **stack);
int		check_dup(t_list **stack);
t_list	*find_min(t_list **stack);
int		reverse_sorted(t_list **stack);

/* setup */
int		l_no_spc(char *str);
int		c_to_i(char	*str, t_list **stack_a);
int		set_up_av(char **av, t_list **stack_a);

/* sort */
void	two_nbrs(t_list **stack_a, char tmp[4]);
void	three_nbrs(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	four_nbrs(t_list **stack_a, t_list **stack_b, char tmp [4]);
void	five_nbrs(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	choose_sort(t_list **stack_a, t_list **stack_b, char tmp[4]);

/* radix_utils */
void	radix(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	ft_range(t_list **stack_a);
void	fill(t_list **stack, int *arr);
void	rank(t_list **stack, int *arr);
void	median_sort(int *array, int n);

/* radix */
void	radix(t_list **stack_a, t_list **stack_b, char tmp[4]);
void	radix_1(t_list **stack_a, t_list **stack_b, char tmp[4], int bit);
void	radix_2(t_list **stack_a, t_list **stack_b, char tmp[4], int bit);

#endif
