##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for mylib
##

CC := gcc -std=gnull
CFLAGS = -W -Wall -Wextra -I./include/

SRC	=	pmy_putstr.c		\
		pmy_put_nbr.c		\
		pmy_putchar.c           \
		pflag_d.c		\
		pflag_i.c		\
		pflag_c.c		\
		pflag_s.c		\
		pflag_percent.c		\
		pflag_o.c		\
		pmy_put_octal.c		\
		pflag_u.c		\
		pmy_put_unbr.c		\
		pflag_x_min.c		\
		pmy_put_hexa_min.c	\
		pflag_x_maj.c		\
		pmy_put_hexa_maj.c	\
		pflag_p.c		\
		pmy_put_hexa_min_long.c	\
		pflag_n.c		\
		my_find_prime_sup.c     \
        my_isneg.c              \
        my_put_nbr.c            \
        my_strlen.c             \
        my_revstr.c             \
        my_is_prime.c           \
		my_getnbr.c             \
        my_putchar.c            \
		my_putstr.c             \
        my_swap.c               \
		my_strcapitalize.c      \
        my_strcat.c             \
		my_strcmp.c             \
        my_strcpy.c             \
        my_strstr.c             \
        my_str_isalpha.c        \
        my_str_islower.c        \
        my_str_isnum.c          \
		my_str_isupper.c        \
        my_strlowcase.c         \
        my_strncat.c            \
        my_strncmp.c            \
		my_strncpy.c            \
        my_strupcase.c		\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../../libmy.a

all:	$(NAME)

$(NAME):
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@cp my.h ../../include/

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
