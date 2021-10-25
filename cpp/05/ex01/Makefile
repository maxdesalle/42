# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/10/25 16:17:14 by maxdesall        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	  Bureaucrat.cpp \
	  Form.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean re fclean
