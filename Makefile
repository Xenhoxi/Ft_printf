# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 23:06:56 by ljerinec          #+#    #+#              #
#    Updated: 2022/11/30 17:38:01 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_hexa.c \
		ft_putstr.c \

OBJECTS = $(SRC:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	AR -rc $@ $?

%.o:  %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
