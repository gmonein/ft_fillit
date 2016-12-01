# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 16:34:46 by jpeguet           #+#    #+#              #
#    Updated: 2016/12/01 20:33:59 by gmonein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

FLAGS = -Wall -Wextra -Werror

HEADERS = include/fillit.h

DIR_S = sources/

SRC = $(DIR_S)ft_place.c \
	$(DIR_S)ft_strlen.c \
	$(DIR_S)ft_list_valid.c \
	$(DIR_S)ft_new_fill.c \
	$(DIR_S)ft_data_one.c \
	$(DIR_S)ft_data_two.c \
	$(DIR_S)ft_data_three.c \
	$(DIR_S)ft_data_four.c \
	$(DIR_S)ft_data_five.c \

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
