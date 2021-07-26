# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 09:20:39 by mdesalle          #+#    #+#              #
#    Updated: 2021/07/26 17:39:38 by maxdesall        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ccgreen = "\033[0;92m"
ccwhite = "\033[0;0m"

NAME = push_swap

TESTER = tester

CC = gcc

CFLAGS = -Wall -Wextra -fsanitize=address

SRC = src/push_swap.c \
      src/list/create.c \
      src/list/one_save.c \
      src/list/multi_save.c \
      src/list/median.c \
      src/utilities/atoi.c \
	  src/utilities/return.c \
	  src/utilities/utils.c \
	  src/algorithm/five.c \
	  src/algorithm/hundred.c \
	  src/algorithm/utils.c \
	  src/algorithm/calc.c \
	  src/algorithm/placer.c \
	  src/algorithm/value.c \
	  src/conditions/next.c \
	  src/conditions/prev.c \
	  src/conditions/b.c \
	  src/moves/sa.c \
      src/moves/sb.c \
      src/moves/ss.c \
      src/moves/ra.c \
      src/moves/rb.c \
      src/moves/rr.c \
      src/moves/rra.c \
      src/moves/rrb.c \
      src/moves/rrr.c \
      src/moves/pa.c \
      src/moves/pb.c

TEST = test/src/tester.c \
	   test/src/ft_itoa.c \
	   test/src/ft_intlen.c \
	   test/src/ft_strlen.c \
	   test/src/ft_strcat.c \
	   test/src/ft_atoi.c \
	   test/src/ft_putnbr.c \
	   test/src/ft_putchar.c

OBJ = $(SRC:.c=.o)

all: $(NAME) $(TESTER)
	@printf $(ccgreen)
	@echo "Successfully compiled"
	@printf $(ccwhite)

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
