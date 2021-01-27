# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 14:49:28 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/27 15:03:28 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX = mlxopengl

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/cub3D.c \
      src/ft_error_check.c \
      src/ft_utilities_one.c

OBJ = $(SRC:.c=.o)

ccgreen = "\033[0;92m"

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	@printf $(ccgreen)
	@echo "Successfully cleaned"

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	@printf $(ccgreen)
	@echo "Successfully cleaned, including the executable"

fcleanre:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fcleanre all
