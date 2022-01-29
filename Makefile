# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:42:31 by rnishimo          #+#    #+#              #
#    Updated: 2022/01/29 22:25:07 by rnishimo         ###   ########.fr        #
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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

ifeq ($(findstring debug, $(MAKECMDGOALS)), debug)
DEBUG = -D DEBUG=1
endif

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) *.gch
	$(RM) $(OBJS)

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
	norminette | grep Error

.PHONY: debug
debug: re

.PHONY: t
t:
	make debug
	gcc ./.test/temp.c $(NAME)
	./a.out
