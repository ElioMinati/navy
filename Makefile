##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Iinclude/ -Llib/my/ -lmy -g

SRC = 	main.c \
		error_handling.c 	\
		comunication.c \
		player_connection.c 	\
		game_handling/game_end.c 	\
		game_handling/game_start.c 	\
		game_handling/game_attack_handling.c 	\
		array2d.c

OBJ = $(SRC:.c=.o)

NAME = navy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
