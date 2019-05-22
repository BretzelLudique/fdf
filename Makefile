# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:51:13 by czhang            #+#    #+#              #
#    Updated: 2018/11/23 09:15:30 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft/libft.a

FILE =	main.c\
	parse.c\
	coord.c\
	draw.c\
	tab_type.c\
	get_next_line.c\

INC = -I libft/includes

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

#FLAG = -Wall -Werror -Wextra

CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) -L libft/ -lft -lmlx -lXext -lX11

$(LIB) :
	make -C libft/ all

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
