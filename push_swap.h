/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:33:25 by jcarlen           #+#    #+#             */
/*   Updated: 2022/05/04 16:34:12 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_place
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*bot_a;
	t_list	*bot_b;
	t_list	*min_b;
	t_list	*max_a;
	t_list	*start;
	int		median;
	t_list	*closest;
}					t_place;

int		push_swap(int ac, char **av);
int		check_if_digit(int ac, char **av);
int		ft_error(t_list **a);
void	two_nbrs(t_list **stack_a);
void	three_nbrs(t_list **stack_a);
void	four_nbrs(t_list **stack_a, t_list **stack_b);
void	five_nbrs(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);
void	check_last(t_list **last);
void	sa(t_list **stack_a, char letter);
void	sb(t_list **stack_b, char letter);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, char letter);
void	rb(t_list **stack_b, char letter);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, char letter);
void	rrb(t_list **stack_b, char letter);
void	rrr(t_list **stack_a, t_list **stack_b);
int		l_no_spc(char *str);
int		c_to_i(char	*str, t_list **stack_a);
void	set_up_str(t_list **stack_a, char **av);
int		set_up_av(int ac, char **av, t_list **stack_a, t_list **stack_b);
void	print_lst(t_list **stack_a, t_list **stack_b);
void	choose_sort(t_list **stack_a, t_list **stack_b);
void	set_previous(t_list **stack);
t_list	*find_max(t_list **stack);
t_list	*find_min(t_list **stack);
int		check_sorted(t_list **stack);
int		check_dup(t_list **stack);
int		median(t_list **stack_a);
void	jifas(t_list **stack_a, t_list **stack_b);
void	init_place(t_list **stack_a, t_list **stack_b, t_place *plc);
t_list	*compare(t_place *plc);
void	tester(t_list **stack_a, t_list **stack_b);//a enlevé
int		rotate_to(t_list **stack, t_list *ptr);
t_list	*gimi_median(t_list **stack_a, int median);
int		abs(int n);
void	median_sort(int *array, int n);
void	ft_range(t_list **stack_a);
void	fill(t_list **stack, int *arr);
void	rank(t_list **stack, int *arr);
int		solver(t_list **stack_a, t_list **stack_b, t_place *plc);
int		is_empty(t_list *list);
t_list	*ft_lstlast_solved(t_list *lst);
int		reverse_sorted(t_list **stack);
int		check_solved(t_list **stack);

#endif

/* 
regler le lst_clear
(abomination rangement + longueur des fonctions)
*/

/*
Algo des amis
-------------
gerer la boucle while de l'algo jifas
gerer le "sa" dans la boucle jifas
tout l'algo omegalul
créer le preneur de decision pour optiminiser (ra/rra) (gérer les rotations -> un certain pointeur)
comparateur du nombre de move entre jifas et radix
clean le .h
enlever les printf(oui!même ceux en commantaire!)
*/