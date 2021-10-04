# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/10/04 17:16:27 by maxdesall        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	  Zombie.cpp \
	  ZombieHorde.cpp \
	  newZombie.cpp \
	  randomChump.cpp

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

.PHONY: all test clean re fclean
