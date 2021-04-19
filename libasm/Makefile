NAME =		libasm.a

SRC =		src/ft_strlen.s

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
		@printf $(ccgreen)
		@echo "Successfully cleaned"

fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)
		rm -rf test
		@printf $(ccgreen)
		@echo "Successfully cleaned, including the excecutable"

fcleanre:
		rm -rf $(OBJ)
		rm -rf $(NAME)
		rm -rf test

re:		fcleanre all
