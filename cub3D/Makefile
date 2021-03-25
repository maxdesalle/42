# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 19:54:25 by mdesalle          #+#    #+#              #
#    Updated: 2021/03/25 10:42:01 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_DIR = minilibX

MLX = libmlx.dylib

SRC = src/cub3d.c \
      src/ft_map_check.c \
      src/ft_error.c \
      src/get_next_line.c \
      src/get_next_line_utils.c \
      src/ft_save.c \
      src/ft_dh.c \
      src/ft_key.c \
      src/ft_move \
      src/ft_texture \
      src/ft_exit.c \
      src/ft_utils.c \

OBJ = $(SRC:.c=.o)

ccgreen = "\033[0;92m"

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx
	@install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)
#	@$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(SRC) -o $(NAME)

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
