# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleverge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 17:32:58 by lleverge          #+#    #+#              #
#    Updated: 2016/07/26 17:25:14 by lleverge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
SRC = main.c	tools.c		term_init.c		ft_dblist.c\
	ft_display.c	ft_keyboard.c	ft_key2.c	ft_ret.c\
	tools2.c	ft_sign.c	ft_size.c
OBJ = $(SRC:.c=.o)
LIB = -L./libft -lft -ltermcap
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY : all clean fclean re
