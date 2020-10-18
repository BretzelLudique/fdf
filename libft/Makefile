# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarole <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 16:39:22 by ccarole           #+#    #+#              #
#    Updated: 2019/09/19 01:21:10 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCN	=	ft_atoi.c \
			ft_bzero.c \
			ft_error.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstr_len.c \
			ft_recursive_power.c \
			ft_repeat_alpha.c \
			ft_sort_param.c \
			ft_sqrt.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c\
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_swap.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c\
			ft_cntwrd2.c\
			ft_cntwrdn.c
SRCS	=	$(addprefix $(SRCP), $(SRCN))
CC		=	gcc
OBJP	=	obj/
SRCP	=	./
OBJ		=	$(addprefix $(OBJP), $(SRCN:.c=.o))
FLAGS	=	-Wall -Wextra -Werror -I includes/
DFLAGS	=	-g
ARRC	=	ar rc

all: $(NAME)

$(NAME): $(OBJP) $(OBJ)
	$(ARRC) $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJP):
	mkdir $(OBJP)

$(OBJP)%.o : $(SRCP)%.c
	$(CC) $(FLAGS) $(DFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJP)

fclean: clean
	rm -rf $(NAME)

re: fclean all
