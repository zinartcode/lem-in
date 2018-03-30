# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 21:00:37 by azinnatu          #+#    #+#              #
#    Updated: 2018/03/29 22:50:29 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

SRC =	main.c \
		solve.c \
		rooms.c \
		links.c \

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = lem_in.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all : $(NAME)

$(NAME): $(OBJ)
	@make re -C libft
	@make -C libft/ft_printf
	@$(CC) -o $(NAME) $(SRCS) $(FLAG) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)lem-in: creating object files"

clean:
	@/bin/$(RM) $(OBJ)
	@make -C libft clean
	@make -C libft/ft_printf clean

fclean: clean
	@make -C libft clean
	@make -C libft/ft_printf clean
	@/bin/$(RM) $(NAME)
	@echo "$(RED)lem-in: deleting object files"

re: fclean all

.PHONY: all clean fclean re
