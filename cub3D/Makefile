# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 14:49:28 by mdesalle          #+#    #+#              #
#    Updated: 2021/03/24 08:06:20 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -fsanitize=address

MLX_DIR = minilibX

MLX = libmlx.dylib

SRC = src/cub3d.c \
      src/ft_resolution.c \
      src/ft_textures.c \
      src/ft_mapcheck.c \
      src/ft_map.c \
      src/ft_error_check.c \
      src/ft_utilities_one.c \
      src/get_next_line.c \
      src/get_next_line_utils.c \
      src/ft_initiation.c \
      src/ft_sprite.c \
      src/ft_exit.c \
      src/ft_visual_one.c \
      src/ft_visual_two.c \
      src/ft_move.c \
      src/ft_sprite_utilities.c \
      src/ft_keys.c \
	  src/ft_save.c

OBJ = $(SRC:.c=.o)

ccgreen = "\033[0;92m"

all: $(NAME)

$(NAME): $(OBJ)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx
#	@install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(SRC) -o $(NAME)

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
