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

NAME = libft.a

FILE = ft_strlcat.c\
       ft_strchr.c\
       ft_memset.c\
       ft_bzero.c\
       ft_memcpy.c\
       ft_memccpy.c\
       ft_memmove.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_strlen.c\
       ft_strdup.c\
       ft_strcpy.c\
       ft_strncpy.c\
       ft_strcat.c\
       ft_strncat.c\
       ft_strrchr.c\
       ft_strstr.c\
       ft_strnstr.c\
       ft_strcmp.c\
       ft_strncmp.c\
       ft_atoi.c\
       ft_isalpha.c\
       ft_isdigit.c\
       ft_isalnum.c\
       ft_isascii.c\
       ft_isprint.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_memalloc.c\
       ft_memdel.c\
       ft_strnew.c\
       ft_strdel.c\
       ft_strclr.c\
       ft_striter.c\
       ft_striteri.c\
       ft_strmap.c\
       ft_strmapi.c\
       ft_strequ.c\
       ft_strnequ.c\
       ft_strsub.c\
       ft_strjoin.c\
       ft_strtrim.c\
       ft_strsplit.c\
       ft_cntwrd.c\
       ft_itoa.c\
       ft_putchar.c\
       ft_putstr.c\
       ft_putendl.c\
       ft_putnbr.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c\
       ft_putendl_fd.c\
       ft_putnbr_fd.c\
       ft_lstnew.c\
       ft_lstdelone.c\
       ft_lstdel.c\
       ft_lstadd.c\
       ft_lstiter.c\
       ft_lstmap.c\
       NAME = test_gnl

INC = -I includes

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

FLAG = -Wall -Werror -Wextra

CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) -L libft/ -lft

$(LIB) :
	make -C libft/ all

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re