# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 18:36:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/10/01 11:41:18 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = libft.h

SRC	=	ft_splitpath.c			\
		ft_strlen.c				\
		ft_numlen.c				\
		ft_tablen.c				\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_strncpy.c			\
		ft_strlcpy.c			\
		ft_strcat.c				\
		ft_strlcat.c			\
		ft_strdup.c				\
		ft_substr.c				\
		ft_join.c				\
		ft_split.c				\
		ft_trim.c				\
		ft_space.c				\
		ft_concat.c				\
		ft_putstr_fd.c			\
		ft_isalpha.c			\
		ft_isnumber.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_atoi.c				\
		ft_itoa.c				\
		ft_split_quotes.c		\
		ft_intlen.c				\
		ft_strchr.c

OBJS = $(SRC:%.c=%.o)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJB)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
