# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 14:40:00 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/25 11:59:25 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard src/*/*.c)

OBJ = ${SRC:.c=.o}

ccgreen = "\033[0;92m"

%.o: %.c
	${CC} ${CFLAGS} -I include -c $^ -o $@

all: ${NAME}

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}
	@printf $(ccgreen)
	@echo "Library successfully compiled"

clean:
	rm -rf $(OBJ)
	@printf $(ccgreen)
	@echo "Library successfully cleaned"

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	@printf $(ccgreen)
	@echo "Library successfully cleaned, including the libft.a file"

fcleanre:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fcleanre all
