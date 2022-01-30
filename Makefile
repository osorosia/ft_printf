# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:42:31 by rnishimo          #+#    #+#              #
#    Updated: 2022/01/30 19:58:17 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
	parser.c \
	parser_error.c \
	get_c.c \
	get_s.c \
	get_p.c \
	get_d.c \
	get_u.c \
	get_x.c \
	get_xx.c \
	get_per.c \
	print.c \
	init_struct_print.c \
	set_number_base.c \
	debug.c \
	debug1.c \

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

ifeq ($(findstring debug, $(MAKECMDGOALS)), debug)
DEBUG = -D DEBUG=1
endif

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) $(DEBUG) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(NAME)

.PHONY: fclean
fclean: clean
	rm -f $(OBJS)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all

.PHONY: test
test: re
	cd .test && bash test.sh
	cd ..
	make fclean

.PHONY: norm
norm:
	norminette | grep Error | cat

.PHONY: debug
debug: re

.PHONY: t
t:
	make debug
	gcc ./.test/temp.c $(NAME)
	valgrind --leak-check=full ./a.out

.PHONY: tt
tt:
	make debug
	gcc ./.test/temp.c $(NAME)
	./a.out
