# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 14:49:28 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/29 11:34:44 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX = mlxopengl

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/cub3d.c \
      src/ft_error_check.c \
      src/ft_utilities_one.c \
      src/get_next_line.c \
      src/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

ccgreen = "\033[0;92m"

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)

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
