# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 16:34:46 by jpeguet           #+#    #+#              #
#    Updated: 2016/11/16 17:43:19 by jpeguet          ###   ########.fr        #
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
