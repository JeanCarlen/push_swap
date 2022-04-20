# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 11:12:30 by jcarlen           #+#    #+#              #
#    Updated: 2022/04/20 15:52:12 by jcarlen          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -w

NAME =	push_swap

SRCS =	push_swap.c\
		push_swap_utils.c\
		push_swap_sort.c\
		push_swap_move.c\
		push_swap_check.c

INCLUDES = push_swap.h

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/

all : libft $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

libft:
		@ $(MAKE) bonus libft.a -C $(LIBFT)

%.o : %.c
		$(CC) $(FLAGS) $< -c

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft reset bonus