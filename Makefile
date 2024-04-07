##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile for my_radar
##

CFLAGS	= 		-W -Wall -Wextra -g

LIB = -I./include/ -L./ -lmy

SRC =	src/main.c	\
		src/init.c	\
		src/display.c	\
		src/recup.c		\
		src/move.c		\
		src/destroy.c	\
		src/collide.c	\
		src/texts.c

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all: buildlib
	 gcc -o my_radar $(SRC) $(LIB) $(CFLAGS) $(CSFML)

buildlib:
	make -C./lib/my -s
clean:
	make -C./lib/my -s clean

fclean:
	make -C./lib/my -s fclean
	rm my_radar

re:	fclean all

.PHONY:	all buildlib clean fclean re
