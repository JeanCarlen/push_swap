/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:25 by jcarlen           #+#    #+#             */
/*   Updated: 2022/04/04 14:55:46 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PS_BUFFSIZE 10

# include "libft/libft.h"

typedef struct	s_pusw
{
	int		*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
	int		pivot;
	int		max;
	int		max_n;
	int		ps_count;
    char	ps_buff[PS_BUFFSIZE];
}                   t_pusw;

int		push_swap(int ac, char **av);

int		check_if_sorted(char **av); // avance dans l'array et regarde si (current < next  || current->next next->next)
int 	check_if_dup(char **av);
int		find_length(); //check la longeur de la list de chiffre
int		small_sort();//sort la stack si find_length est moins que 5 
int		big_sort();//sort la stack si find_length est + que 5
void	print_move();//print dans le terminal les move effectués par le sort
int		print_solution();
int		get_rdm_nbr();//generateur de nombre random	||prog different||
int		sa();//Swap the first 2 elements at the top of stack a
int		sb();//Swap the first 2 elements at the top of stack b
int		ss();//sa and sb at the same time.
int		pa();//Take the first element at the top of b and put it at the top of a
int		pb();//Take the first element at the top of a and put it at the top of b
int		ra();//Shift up all elements of stack a by 1.The first element becomes the last one
int		rb();//Shift up all elements of stack b by 1.The first element becomes the last one
int		rr();//ra and rb at the same time
int		rra();//Shift down all elements of stack a by 1.The first element becomes the last one
int		rrb();//Shift down all elements of stack b by 1..The first element becomes the last one
int		rrr();//rra and rrb at the same time.
static t_pusw	*ps_struct_init(int argc, char **argv); //mettre l'argv dans une liste chainée et creer le pointeur de la list b


#endif