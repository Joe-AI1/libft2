# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elwilks <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 22:55:11 by elwilks           #+#    #+#              #
#    Updated: 2025/12/03 22:55:12 by elwilks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra

SRC		:=	ft_printf.c ft_printf_utils.c

OBJ		:=	$(SRC:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean:		clean
	rm -rf $(NAME)

re:			fclean all
