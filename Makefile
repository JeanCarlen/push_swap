# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 11:12:30 by jcarlen           #+#    #+#              #
#    Updated: 2022/05/04 16:35:33 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -w

NAME =	push_swap

SRCS =	push_swap.c\
		push_swap_utils.c\
		push_swap_sort.c\
		push_swap_move.c\
		push_swap_check.c\
		find.c\
		bug_sort.c\
		radix.c\
		jifas.c\

INCLUDES = push_swap.h

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/

PARAM = "1"

GR = \033[32;1m
RC = \033[0m

all : libft $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
		@printf "\n push_swap=> SUCCESS\n $(RC)"

random: libft 
		gcc numb_gen.c -L$(LIBFT) -lft -o random
		@echo $(ARG)
		@echo $(PARAM)

ARG:
	export ARG= `./random $(PARAM)`
	@echo $(ARG)

libft:
		@ $(MAKE) bonus libft.a -C $(LIBFT)

%.o : %.c
		@$(CC) $(FLAGS) $< -c
		@printf "$(GR)||"

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

run: $(NAME)
		./push_swap $(ARG)
		@ echo "nombres de move"
		@ ./push_swap $(ARG) | wc -l

re: fclean all

.PHONY: all clean fclean re libft reset bonus run
