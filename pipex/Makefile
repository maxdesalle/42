# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/08/03 16:11:58 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"
ccwhite = "\033[0;0m"

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -fsanitize=address

SRC = src/pipex.c \
	  src/data/path.c \
	  src/data/launcher.c \
	  src/data/command.c \
	  src/utilities/ft_split.c \
	  src/utilities/ft_strjoin.c \
	  src/utilities/ft_strdup.c \
	  src/utilities/ft_strncmp.c \
	  src/utilities/ft_strlen.c \
	  src/misc/return.c \
	  src/misc/init.c

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
