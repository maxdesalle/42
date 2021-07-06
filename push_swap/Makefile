# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/07/06 13:09:40 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"

NAME = push_swap

TESTER = tester

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = src/push_swap.c \
      src/list.c \
      src/atoi.c \
      src/return.c \
      src/moves/sa.c \
      src/moves/ra.c \
      src/moves/rra.c

TEST = test/tester.c \
       src/atoi.c \
       src/return.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@printf $(ccgreen)
	@echo "Successfully compiled"

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

test: $(TESTER)
	@printf $(ccgreen)
	@echo "Successfully compiled"

$(TESTER):
	@$(CC) $(CFLAGS) $(TEST) -o $(TESTER)

clean:
	@rm -rf $(OBJ)
	@rm -rf test/tester.o
	@printf $(ccgreen)
	@echo "Successfully cleaned"

fclean:
	@rm -rf $(OBJ)
	@rm -rf test/tester.o
	@rm -rf $(NAME)
	@rm -rf $(TESTER)
	@printf $(ccgreen)
	@echo "Successfully cleaned, including the executable"

fcleanre:
	@rm -rf $(OBJ)
	@rm -rf test/tester.o
	@rm -rf $(NAME)
	@rm -rf $(TESTER)

re:	fcleanre all

.PHONY: all test clean re fcleanre fclean
