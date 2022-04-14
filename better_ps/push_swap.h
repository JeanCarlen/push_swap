/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:25 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/14 12:34:45 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

int		push_swap(int ac, char **av);
int		check_if_sorted(int ac, char **av); // avance dans l'array et regarde si (current < next  || current->next next->next)
int		check_if_dup(int ac, char **av);
int		check_if_digit(int ac, char **av);
int		ft_error(t_list **a);
void	two_nbrs(t_list **stack_a);
void	three_nbrs(t_list **stack_a);
void	check_last(t_list **last);
void	sa(t_list **stack_a, char letter);//Swap the first 2 elements at the top of stack a
void	sb(t_list **stack_b, char letter);//Swap the first 2 elements at the top of stack b
void	ss(t_list **stack_a, t_list **stack_b);//sa and sb at the same time.
void	pa(t_list **stack_b, t_list **stack_a, char letter);//Take the first element at the top of b and put it at the top of a
void	pb(t_list **stack_a, t_list **stack_b, char letter);//Take the first element at the top of a and put it at the top of b
void	ra(t_list **stack_a, char letter);//Shift up all elements of stack a by 1.The first element becomes the last one
void	rb(t_list **stack_b, char letter);//Shift up all elements of stack b by 1.The first element becomes the last one
void	rr(t_list **stack_a, t_list **stack_b);//ra and rb at the same time
void	rra(t_list **stack_a, char letter);//Shift down all elements of stack a by 1.The first element becomes the last one
void	rrb(t_list **stack_b, char letter);//Shift down all elements of stack b by 1..The first element becomes the last one
void	rrr(t_list **stack_a, t_list **stack_b);//rra and rrb at the same time.
int		l_no_spc(char *str);
void	c_to_i(char	*str, t_list **stack_a);
void	set_up_str(t_list **stack_a, char **av);
int		set_up_av(int ac, char **av, t_list **stack_a, t_list **stack_b);
void	print_lst(t_list **lst);
void	choose_sort(t_list **stack_a, t_list **stack_b);

#endif

/* 
ecrire la fonction del
*/