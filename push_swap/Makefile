NAME = push_swap
SOURCES = changetonum.c push_swapfile.c sorting.c pushcommand.c checkercommnad.c pushcommand2.c pushcommand3.c smallswap.c ft_split.c startinginputcheck.c freebox.c
CC = cc
RM = rm -f
OBJ = $(SOURCES:.c=.o)
CFLAG = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)