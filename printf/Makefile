# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 16:09:49 by mdesalle          #+#    #+#              #
#    Updated: 2020/12/07 09:31:48 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/ft_c_craft.c src/ft_analysis.c src/ft_parser.c src/ft_printf.c src/ft_utilities.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
