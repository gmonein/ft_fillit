# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 16:34:46 by jpeguet           #+#    #+#              #
#    Updated: 2016/11/28 23:58:25 by gmonein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, re, clean, fclean

NAME = fillit.a

HEADERS = fillit.h

SRC =

OBJ = $(SRC:.c=.o)

$(NAME):
			@gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADERS)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

all: $(NAME)

clean:
			@rm -f $(OBJ)

fclean:	clean
			@rm -f $(NAME)

re: fclean all

test:
	gcc ./data/*.c ft_place.c ft_strlen.c ft_list_valid.c ft_new_fill.c -I fillit.h
