# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 21:00:37 by azinnatu          #+#    #+#              #
#    Updated: 2018/04/11 23:05:50 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Wextra -Werror -g
CC = gcc

SRC =	main.c \
		solve.c \
		rooms.c \
		links.c \
		init_free.c \
		helpers.c \
		path_helper.c \
		path_finder.c \

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

LIB		= -L libft/ -l ft -L libft/ft_printf/ -l ftprintf
INC		= -I includes/

OB1 = $(SRC:.c=.o)
OBJ = $(SRCS:.c=.o)

SRCDIR = srcs
OBJDIR = objs

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = lem_in.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all : $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C libft/ft_printf
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	$(CC) $(FLAGS) $(LIB) $(OB1) -o $(NAME)
	@echo "$(GREEN)lem-in: creating object files"

rmbin:
	rm -rf $(NAME)

rmobj:
	rm -rf *.o

again: rmbin rmobj all
	

clean:
	@/bin/$(RM) $(OB1)
	@make -C libft clean
	@make -C libft/ft_printf clean

fclean: clean
	@make -C $(dir $(LIBFT)) fclean
	@make -C libft/ft_printf fclean
	@/bin/$(RM) $(NAME)
	@echo "$(RED)lem-in: deleting object files"

re: fclean all

.PHONY: all clean fclean re
