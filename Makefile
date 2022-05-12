# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mancarvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 11:12:30 by jcarlen           #+#    #+#              #
#    Updated: 2022/05/05 15:12:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

NAME =	push_swap

SRCS =	push_swap.c\
		moves_1.c \
		moves_2.c \
		moves_3.c \
		check.c \
		setup.c \
		sort.c \
		radix.c \

INCLUDES = push_swap.h

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/

GR = \033[32;1m
CY = \033[36;1m
RC = \033[0m

all : $(NAME)

$(NAME) : libft start $(OBJS)
		@$(CC) $(OBJS) -L$(LIBFT) -lft $(CFLAGS) -o $(NAME)
		@printf "100%%  => SUCCESS\n$(RC)"
		@ printf "$(CY)**********************\n# PUSH_SWAP COMPILED #\n**********************\n$(RC)"

start:
		@printf "$(GR)Compiling Push_Swap\n"

random: libft 
		gcc numb_gen.c -L$(LIBFT) -lft -o random
		@echo $(ARG)
		@echo $(PARAM)

libft:
		@ $(MAKE) bonus -C $(LIBFT)
		@ printf "$(CY)******************\n# LIBFT COMPILED #\n******************\n$(RC)"

%.o : %.c
		@$(CC) $(FLAGS) $< -c
		@printf "$(GR)||"

clean :
		@ rm -f $(OBJS)
		@ printf "$(CY)******************\n# OBJECT DELETED #\n******************\n$(RC)"
fclean : clean
		@ rm -f $(NAME)
		@ printf "$(CY)******************\n# BINARY DELETED #\n******************\n$(RC)"
reset: fclean 
		@ $(MAKE) fclean -C $(LIBFT)

run: $(NAME)
		@ echo "nombres de move jifas"
		@ ./push_swap $(ARG) | wc -l
		@ echo "nombres de move radix"
		@ ./push_swap2 $(ARG) | wc -l

re: fclean all

.PHONY: all clean fclean re libft reset bonus run start
