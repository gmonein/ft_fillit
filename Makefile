# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 00:21:46 by jpeguet           #+#    #+#              #
#    Updated: 2016/12/02 04:05:00 by jpeg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/ft_place.c \
						./srcs/ft_main.c \
						./srcs/ft_strlen.c \
						./srcs/ft_list_valid.c \
						./srcs/ft_list_tool.c \
						./srcs/ft_convert_tools.c \
						./srcs/ft_data_one.c \
						./srcs/ft_data_two.c \
						./srcs/ft_data_three.c \
						./srcs/ft_data_four.c \
						./srcs/ft_data_five.c \
						./srcs/ft_new_fill.c \
						./srcs/ft_print_map.c \
						./srcs/ft_utility.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADERS = ./include

$(H_MAKE):
				@$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)

$(NAME):
				@$(CC) $(H_MAKE) $(SRCS) -I $(HEADERS) -o $(NAME)

all:$(NAME)

clean:
				@rm -rf $(./)

fclean: clean
				@rm -f $(NAME)

re : fclean all
