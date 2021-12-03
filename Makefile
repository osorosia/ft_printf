# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:42:31 by rnishimo          #+#    #+#              #
#    Updated: 2021/12/03 06:06:07 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
	parser.c \
	get_c.c \
	get_s.c \
	get_p.c \
	set_number_base.c \
	calc_number_of_digit.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME) t

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) *.gch
	$(RM) $(OBJS)

re: fclean all

t: all
	cd test && bash test.sh

.PHONY: all clean fclean re test
