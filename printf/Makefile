# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 16:09:49 by mdesalle          #+#    #+#              #
#    Updated: 2020/12/05 15:36:52 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_analysis.c src/ft_parser.c src/ft_printf.c src/ft_utilities.c \
      src/ft_c_craft.c

OBJ = $(SRC:.c=.o)

INCLUDE = include/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)

$(OBJECTS): $(SRC) $(INCLUDE)
	gcc -Wextra -Werror -Wall -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
