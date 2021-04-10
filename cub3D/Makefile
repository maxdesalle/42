# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 19:54:25 by mdesalle          #+#    #+#              #
#    Updated: 2021/04/10 16:00:10 by mdesalle         ###   ########.fr        #
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
      src/ft_move.c \
      src/ft_texture.c \
      src/ft_exit.c \
      src/ft_utils.c \
      src/ft_sprisual.c \
      src/ft_map.c \
      src/ft_res.c \
      src/ft_sprutils.c \
      src/ft_visinit.c \
      src/ft_arg.c

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
