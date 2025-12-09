NAME = libftprintf.a

SRC = ft_printf.c function1.c function2.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c Makefile
	@$(CC) $(FLAG) -I. -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
