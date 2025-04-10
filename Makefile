NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LIBFT = ./libft/libft.a

SRC = free.c ft_check.c push_swap.c operations.c reverse.c rotate.c utils.c stack.c  swaps.c min_max.c radix_sort.c size_sort.c parse.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C ./libft

clean:
		make clean -C ./libft
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re