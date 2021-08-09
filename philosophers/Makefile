# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/08/09 15:33:06 by maxdesall        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"
ccwhite = "\033[0;0m"

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address

SRC = src/philo.c \
	  src/data/init.c \
	  src/data/check.c \
	  src/data/linker.c \
	  src/data/time.c \
	  src/misc/return.c \
	  src/utilities/ft_atoi.c

OBJ = $(SRC:.c=.o)

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
