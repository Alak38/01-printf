# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atardy <atardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 11:35:32 by atardy            #+#    #+#              #
#    Updated: 2026/10/17 09:10:52 by atardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
MAKE = make
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SOURCES = flag_parsing.c print_i.c print_x.c \
	ft_printf.c	print_c_s.c	print_u.c \
HEAD = ft_printf.h
OBJECTS = $(SOURCES:.c=.o)

bonus : re

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME) : $(OBJECTS) $(HEAD)
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJECTS)

%.o: %.c
		@$(CC) $(CFLAGS) -c $<  -o $(<:.c=.o)

clean: 
	@rm -f $(OBJECTS)
	@$(MAKE) clean -C ./libft
	
fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re
