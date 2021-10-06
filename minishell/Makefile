# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 12:21:19 by mdesalle          #+#    #+#              #
#    Updated: 2021/09/30 19:13:20 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

ccgreen = "\033[0;92m"
ccwhite = "\033[0;0m"

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	LIB = -L/usr/include -I/usr/local/include -lreadline -L./libft -lft
else
	LIB = -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -lreadline -L./libft -lft	
endif

SRC = \
		./src/parser/init_shell.c \
		./src/parser/preparse_shell.c \
		./src/parser/parse_arg.c \
		./src/parser/echo_builtin.c \
		./src/parser/check_quotes.c \
		./src/exec/exec_shell.c \
		./src/exec/pipe_line.c \
		./src/exec/pipeline_utils.c \
		./src/exec/file_redir.c \
		./src/exec/here_doc.c \
		./src/exec/signals.c \
		./src/exec/tilde.c \
		./src/exec/exit.c \
		./src/exec/cd.c \
		./src/env/var.c \
		./src/env/expoorter.c \
		./src/env/unset.c \
		./src/env/export.c \
		./src/env/enver.c \
		./src/utils/ft_presplit.c \
		./src/utils/ft_specialsplit.c \
		./src/utils/ft_split_utils.c \
		./src/utils/free_exit.c \
		./src/utils/reset.c \
		./src/utils/error_msg.c \
		./src/utils/strings.c \
		./src/main.c \
		./src/env/dsh.c \
		./src/env/ranker.c \

OBJ = $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $(LIB) $< -o $@

LIBFT = ./libft/libft.a

$(NAME): $(LIBFT) $(SRC)
		@$(CC) $(SRC) $(CFLAGS) $(LIB) -o $(NAME)

all: $(NAME)
	@printf $(ccgreen)
	@echo "Successfully compiled"
	@printf $(ccwhite)

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
		@rm -rf $(OBJ)
		@cd libft && make clean 
		@printf $(ccgreen)
		@echo "Successfully cleaned"
		@printf $(ccwhite)

fclean:
		@rm -rf $(NAME)
		@cd libft && make fclean
		@printf $(ccgreen)
		@echo "Successfully cleaned, including the executable"
		@printf $(ccwhite)

fcleanre:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re:	fcleanre all

.PHONY: all clean fclean re fcleanre
