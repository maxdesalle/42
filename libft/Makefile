# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 14:40:00 by mdesalle          #+#    #+#              #
#    Updated: 2020/11/30 09:05:46 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard src/*/*.c)

OBJ = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -I include -c $^ -o $@

all: ${NAME}

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
