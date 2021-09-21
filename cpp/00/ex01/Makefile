# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/09/21 16:49:08 by maxdesall        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"
ccwhite = "\033[0;0m"

NAME = phonebook

CC = clang++

CFLAGS = -Wall -Wextra -std=c++98

SRC = phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	@printf $(ccgreen)
	@echo "Successfully compiled"
	@printf $(ccwhite)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@printf $(ccgreen)
	@echo "Successfully cleaned"

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@printf $(ccgreen)
	@echo "Successfully cleaned, including the executable"

fcleanre:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re:	fcleanre all

.PHONY: all test clean re fcleanre fclean
