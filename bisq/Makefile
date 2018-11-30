# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alorent- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 21:02:46 by alorent-          #+#    #+#              #
#    Updated: 2018/10/10 16:24:03 by alorent-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = bscheck.c bsq_grow_b.c bsq_grow_right.c bsq_grow.c bsq_sqr.c \
	  bsqcreate.c main.c output_ft.c

all: $(NAME)

$(NAME):
	@gcc -Wextra -Wall -Werror $(SRC) -o $(NAME)
	@gcc -Wextra -Wall -Werror -c $(SRC)

clean:
	@/bin/rm -f bscheck.o bsq_grow_b.o bsq_grow_right.o bsq_grow.o \
		bsq_sqr.o bsqcreate.o main.o output_ft.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
