# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 09:08:10 by eda-mata          #+#    #+#              #
#    Updated: 2024/06/21 09:11:01 by eda-mata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c utils2.c utils.c operacoes1.c operacoes3.c utils3.c operacoes2.c utils4.c radix.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
