NAME = lem-in

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror -g

SRC =			main.c \
				solve.c 


BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc $(LIB) -o $(NAME) $(BINS)
%.o: %.c
	gcc -c -o $@ $<
clean:
	make -C libft/ clean
	rm -rf $(BINS)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all