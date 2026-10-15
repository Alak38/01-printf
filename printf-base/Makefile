# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atardy <atardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 11:35:32 by atardy            #+#    #+#              #
#    Updated: 2026/10/13 15:26:40 by atardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

SOURCES = ft_printf.c \
		char_str_int.c \
		converter.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

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