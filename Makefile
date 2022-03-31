# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 11:12:30 by jcarlen           #+#    #+#              #
#    Updated: 2022/03/29 13:41:57 by jcarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME =	push_swap

SRCS =	push_swap.c\
		push_swap_utils.c\

INCLUDES = push_swap.h

LIBFT = ./libft/

$(NAME) : $(OBJS)
		$(CC) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

run : ./push_swap

all : libft $(NAME)

libft:
		@ $(MAKE) bonus -C $(LIBFT)

%.o : %.c
		$(CC) $(FLAGS) $< -c

clean :
		rm -f push_swap.o

fclean : clean
		rm -f $(SRCS)

reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft reset bonus