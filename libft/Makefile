# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schakor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 17:56:43 by schakor           #+#    #+#              #
#    Updated: 2018/10/30 13:21:25 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

CPPFLAGS	= 	-I includes

SRC_PATH	=	./srcs

OBJ_PATH	=	./objs

SRC_FILES	=	array/ft_arrdup.c\
				array/ft_arrlen.c\
				array/ft_arrdel.c\
				conversion/ft_atoi.c\
				conversion/ft_itoa.c\
				conversion/ft_tolower.c\
				conversion/ft_toupper.c\
				gnl/get_next_line.c\
				list/ft_lstadd.c\
				list/ft_lstaddlast.c\
				list/ft_lstdel.c\
				list/ft_lstdelone.c\
				list/ft_lstiter.c\
				list/ft_lstlen.c\
				list/ft_lstmap.c\
				list/ft_lstnew.c\
				maths/ft_abs.c\
				maths/ft_max.c\
				maths/ft_min.c\
				memory/ft_bzero.c\
				memory/ft_memalloc.c\
				memory/ft_memccpy.c\
				memory/ft_memchr.c\
				memory/ft_memcmp.c\
				memory/ft_memcpy.c\
				memory/ft_memdel.c\
				memory/ft_memmove.c\
				memory/ft_memset.c\
				output/ft_putchar.c\
				output/ft_putendl.c\
				output/ft_putnbr.c\
				output/ft_putnbrendl.c\
				output/ft_putstr.c\
				output/ft_putchar_fd.c\
				output/ft_putendl_fd.c\
				output/ft_putnbr_fd.c\
				output/ft_putnbrendl_fd.c\
				output/ft_putstr_fd.c\
				string/ft_strcat.c\
				string/ft_strcpy.c\
				string/ft_striter.c\
				string/ft_strlcat.c\
				string/ft_strncat.c\
				string/ft_strnew.c\
				string/ft_strstr.c\
				string/ft_strchr.c\
				string/ft_strdel.c\
				string/ft_striteri.c\
				string/ft_strlen.c\
				string/ft_strncmp.c\
				string/ft_strnstr.c\
				string/ft_strsub.c\
				string/ft_strclr.c\
				string/ft_strdup.c\
				string/ft_strjoin.c\
				string/ft_strmap.c\
				string/ft_strncpy.c\
				string/ft_strrchr.c\
				string/ft_strtrim.c\
				string/ft_strcmp.c\
				string/ft_strequ.c\
				string/ft_strjoinjoin.c\
				string/ft_strfreejoin.c\
				string/ft_strmapi.c\
				string/ft_strnequ.c\
				string/ft_strsplit.c\
				type/ft_isalnum.c\
				type/ft_isascii.c\
				type/ft_isescaped.c\
				type/ft_isprint.c\
				type/ft_isupper.c\
				type/ft_isalpha.c\
				type/ft_isdigit.c\
				type/ft_islower.c\
				type/ft_isquote.c\
				type/ft_strtolower.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

RM			= 	rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJS))

clean :
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
