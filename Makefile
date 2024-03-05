##
## EPITECH PROJECT, 2023
## cpool day10
## File description:
## Makefile printf
##

SRC =	lib/my/check_flags.c	\
		lib/my/flag_discp.c	\
		lib/my/flag_oux.c	\
		lib/my/flag_pfe.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_isneg.c	\
		lib/my/my_printf.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_showmem.c	\
		lib/my/my_showstr.c	\
		lib/my/my_sort_int_array.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strstr.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_swap.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME_PROJ	=	mysh

NAME_HEADER	=	my.h

INCLUDE_DIR	=	./include/

CFLAGS	=	-Wall -I$(INCLUDE_DIR)

all:	$(NAME_PROJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	cd ../..
	rm -rf $(NAME_PROJ)

re:	fclean	all

$(NAME_PROJ):
	gcc lib/my/*.c src/*.c -o $(NAME_PROJ) $(CFLAGS) -g3
