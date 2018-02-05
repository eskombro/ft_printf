# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 19:45:21 by sjimenez          #+#    #+#              #
#    Updated: 2018/01/16 20:55:28 by sjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c		\
		options.c		\
		conversion.c	\
		parsing.c		\
		unicode.c		\
		ft_asprintf.c	\
		ft_dprintf.c	\
		ft_vprintf.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	make -C libft
	gcc -Wall -Wextra -Werror -I libft/libft.h -I $(HEADER) -c $(SRCS)
	cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJS)

clean:
	make -C libft clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
