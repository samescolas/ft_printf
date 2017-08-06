# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sescolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 09:59:58 by sescolas          #+#    #+#              #
#    Updated: 2017/08/05 16:39:41 by sescolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = libft.h

SRCS = 	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $@ *.o
	ranlib $@

$(OBJS): $(SRCS) $(HEADER)
	@if [ $@ =  "ft_fatal.o" ]; then \
		$(CC) $(CFLAGS) -I ../includes -c $(subst .o,.c,$@) -o $@; \
	else \
		$(CC) $(CFLAGS) -c $(subst .o,.c,$@) -o $@; \
	fi;

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
