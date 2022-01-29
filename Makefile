# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:42:31 by rnishimo          #+#    #+#              #
#    Updated: 2022/01/29 15:39:11 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
	parser.c \
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
	calc_number_of_digit.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

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
test: all
	cd .test && bash test.sh
	cd ..
	make fclean

.PHONY: norm
norm:
	norminette | grep Error

.PHONY: t
t: all
	gcc ./.test/temp.c $(NAME)
	./a.out
