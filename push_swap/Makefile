# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/06/07 14:19:19 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c \
      src/list.c \
      src/utils.c \
      src/sort.c \
      src/atoi.c \
      src/return.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@printf $(ccgreen)
	@echo "Successfully compiled"

$(NAME):
	@$(CC) $(SRC) -o $(NAME)

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
