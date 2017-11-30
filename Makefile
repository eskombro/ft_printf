# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:25:17 by sjimenez          #+#    #+#              #
#    Updated: 2017/11/30 06:42:20 by sjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS_DIR = srcs/

INCLUDES = includes/

LIBFT_INCLUDES = libft/includes

LIB = libft -lft

SRC = ft_printf.c		\
	  get_damn_flags.c	\
	  i_am_d.c			\
	  i_am_p.c			\
	  i_am_s.c			\

SRC_O = $(addprefix $(SRCS_DIR),  $(SRC:.c=.o))

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) -o $@ $< -I $(INCLUDES) -I $(LIBFT_INCLUDES)

$(NAME): $(SRC_O)
	@echo " \033[0;32m\n----- Compiling Libft ----------\033[0;0m"
	@make -C libft
	@echo " \033[0;32m\n----- Compiling sources --------\033[0;0m"
	ar rcs $(NAME) $(SRC_O) libft/libft.a
	ranlib $(NAME)
	@echo " \033[0;32m\n----- ft_printf compiled -----\033[0;0m"
	@echo "libftprintf.a created"

clean:
	@rm -Rf $(SRC_O)
	@make -C libft clean
	@echo "ft_printf clean executed"
	
fclean: clean
	@rm -Rf $(NAME)
	@make -C libft fclean
	@echo "ft_printf fclean executed"

re: fclean all

.PHONY: re clean fclean all
