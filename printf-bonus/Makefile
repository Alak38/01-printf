# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atardy <atardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 11:35:32 by atardy            #+#    #+#              #
#    Updated: 2026/10/15 12:25:50 by atardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

SOURCES = flag_parsing.c ft_printf.h print_i.c print_x.c \
ft_printf.c	print_c_s.c	print_u.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDE = /libft

CFLAGS = -Wall -Wextra -Werror -I INCLUDE

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

clean: 
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re