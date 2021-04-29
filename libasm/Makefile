# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 10:32:10 by mdesalle          #+#    #+#              #
#    Updated: 2021/04/19 10:32:22 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a

SRC =		src/ft_strlen.s \
		src/ft_write.s \
		src/ft_read.s \
		src/ft_strcmp.s \
		src/ft_strcpy.s \
		src/ft_strdup.s

OBJ =		$(SRC:.s=.o)

CC =		clang

NASM =		nasm -f elf64

ccgreen =	"\033[0;92m"

%.o : %.s
		$(NASM) $<

all: 		$(NAME)

$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ)

test:		
		$(CC) src/main.c $(NAME) -o test

clean:
		rm -rf $(OBJ)
		rm -rf test
		rm -rf test.txt
		@printf $(ccgreen)
		@echo "Successfully cleaned"

fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)
		rm -rf test
		rm -rf test.txt
		@printf $(ccgreen)
		@echo "Successfully cleaned, including the excecutable"

fcleanre:
		rm -rf $(OBJ)
		rm -rf $(NAME)
		rm -rf test
		rm -rf test.txt

re:		fcleanre all
