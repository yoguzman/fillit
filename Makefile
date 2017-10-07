#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguzman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 11:38:09 by yguzman           #+#    #+#              #
#    Updated: 2016/11/14 13:09:31 by yguzman          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=		clang

ARRC		=		ar rc

RANLIB		=		ranlib

NAME_LIB	=		libft/libft.a

NAME		=		fillit

DIR_SRC_LIB	=		./libft/

DIR_SRC		=		./src/

SRCS_LIB	=		$(DIR_SRC_LIB)ft_memset.c		\
					$(DIR_SRC_LIB)ft_bzero.c		\
					$(DIR_SRC_LIB)ft_memcpy.c		\
					$(DIR_SRC_LIB)ft_memccpy.c		\
					$(DIR_SRC_LIB)ft_memmove.c		\
					$(DIR_SRC_LIB)ft_memchr.c		\
					$(DIR_SRC_LIB)ft_memcmp.c		\
					$(DIR_SRC_LIB)ft_strlen.c		\
					$(DIR_SRC_LIB)ft_strdup.c		\
					$(DIR_SRC_LIB)ft_strcpy.c		\
					$(DIR_SRC_LIB)ft_strncpy.c		\
					$(DIR_SRC_LIB)ft_strcat.c		\
					$(DIR_SRC_LIB)ft_strncat.c		\
					$(DIR_SRC_LIB)ft_strlcat.c		\
					$(DIR_SRC_LIB)ft_strchr.c		\
					$(DIR_SRC_LIB)ft_strrchr.c		\
					$(DIR_SRC_LIB)ft_strstr.c		\
					$(DIR_SRC_LIB)ft_strnstr.c		\
					$(DIR_SRC_LIB)ft_strcmp.c		\
					$(DIR_SRC_LIB)ft_strncmp.c		\
					$(DIR_SRC_LIB)ft_atoi.c			\
					$(DIR_SRC_LIB)ft_isalpha.c		\
					$(DIR_SRC_LIB)ft_isdigit.c		\
					$(DIR_SRC_LIB)ft_isalnum.c		\
					$(DIR_SRC_LIB)ft_isascii.c		\
					$(DIR_SRC_LIB)ft_isprint.c		\
					$(DIR_SRC_LIB)ft_toupper.c		\
					$(DIR_SRC_LIB)ft_tolower.c		\
					$(DIR_SRC_LIB)ft_memalloc.c		\
					$(DIR_SRC_LIB)ft_memdel.c		\
					$(DIR_SRC_LIB)ft_strnew.c		\
					$(DIR_SRC_LIB)ft_strdel.c		\
					$(DIR_SRC_LIB)ft_strclr.c		\
					$(DIR_SRC_LIB)ft_striter.c		\
					$(DIR_SRC_LIB)ft_striteri.c		\
					$(DIR_SRC_LIB)ft_strmap.c		\
					$(DIR_SRC_LIB)ft_strmapi.c		\
					$(DIR_SRC_LIB)ft_strequ.c		\
					$(DIR_SRC_LIB)ft_strnequ.c		\
					$(DIR_SRC_LIB)ft_strsub.c		\
					$(DIR_SRC_LIB)ft_strjoin.c		\
					$(DIR_SRC_LIB)ft_strtrim.c		\
					$(DIR_SRC_LIB)ft_strsplit.c		\
					$(DIR_SRC_LIB)ft_itoa.c			\
					$(DIR_SRC_LIB)ft_putchar.c		\
					$(DIR_SRC_LIB)ft_putstr.c		\
					$(DIR_SRC_LIB)ft_putendl.c		\
					$(DIR_SRC_LIB)ft_putnbr.c		\
					$(DIR_SRC_LIB)ft_putchar_fd.c	\
					$(DIR_SRC_LIB)ft_putstr_fd.c	\
					$(DIR_SRC_LIB)ft_putendl_fd.c	\
					$(DIR_SRC_LIB)ft_putnbr_fd.c	\
					$(DIR_SRC_LIB)ft_lstnew.c		\
					$(DIR_SRC_LIB)ft_lstdelone.c	\
					$(DIR_SRC_LIB)ft_lstdel.c		\
					$(DIR_SRC_LIB)ft_lstadd.c		\
					$(DIR_SRC_LIB)ft_lstiter.c		\
					$(DIR_SRC_LIB)ft_lstmap.c		\
					$(DIR_SRC_LIB)ft_lstreverse.c	\
					$(DIR_SRC_LIB)ft_lstpushback.c	\
					$(DIR_SRC_LIB)ft_lstsize.c		\
					$(DIR_SRC_LIB)ft_lstpop.c		\
					$(DIR_SRC_LIB)ft_strtabdel.c	\
					$(DIR_SRC_LIB)ft_strtablen.c	\

SRCS		=		$(DIR_SRC)read_tetri.c				\
					$(DIR_SRC)check_tetri.c				\
					$(DIR_SRC)main.c					\
					$(DIR_SRC)tools_algo.c				\
					$(DIR_SRC)del_tetri_in_list.c		\
					$(DIR_SRC)fillit_iter.c				\
					$(DIR_SRC)print_map.c				\

OBJS_LIB	=		$(SRCS_LIB:.c=.o)

OBJS		=		$(SRCS:.c=.o)

CFLAGS		+=		-Iinclude
CFLAGS		+=		-Wall -Wextra

RM			=		rm -f

ECHO		=		printf

all			:		$(NAME)


$(NAME)		:		$(NAME_LIB) $(OBJS)
					@$(ECHO) "\033[35m[~~~~COMPILATION PROJECT~~~~]\n\033[0m"
					@$(CC) -o $(NAME) -Llibft -lft $(OBJS) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" || $(ECHO) "\033[31m["$@"]\n\033[0m"

$(NAME_LIB)	:		$(OBJS_LIB)
					@$(ECHO) "\033[35m[~~~~~~COMPILATION LIB~~~~~~]\n\033[0m"
					@$(ARRC) $(NAME_LIB) $(OBJS_LIB) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" && $(RANLIB) $(NAME_LIB) || $(ECHO) "\033[31m"$@"\n\033[0m"

%.o			:		%.c
					@$(ECHO) "\033[35m[~~~Comipilation obj~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m" || $(ECHO) "\033[31m ["$@"]\n\033[0m"

clean		:
					@$(ECHO) "\033[31m[~~~~~~Supression des .o~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)
					@$(RM) $(OBJS_LIB)

fclean		:		clean
					@$(ECHO) "\033[31m[~~~~Supression de lib_ft.a et du Binaire~~~~]\n\033[0m"
					@$(RM) $(NAME)
					@$(RM) $(NAME_LIB)

re			:		fclean all

depend		:		$(SRCS) $(SRCS_LIB)
					makedepend -- -Yinclude/ -- $^

.PHONY		:		all depend clean flean re

# DO NOT DELETE THIS LINE -- make depend depends on it.

src/read_tetri.o: include/libft.h include/fillit.h
src/check_tetri.o: include/libft.h include/fillit.h
src/main.o: include/fillit.h include/libft.h
src/del_tetri_in_list.o: include/fillit.h include/libft.h
src/fillit_iter.o: include/fillit.h include/libft.h
src/print_map.o: include/libft.h include/fillit.h
libft/ft_bzero.o: include/libft.h
libft/ft_strdup.o: include/libft.h
libft/ft_strncpy.o: include/libft.h
libft/ft_strncat.o: include/libft.h
libft/ft_strlcat.o: include/libft.h
libft/ft_strrchr.o: include/libft.h
libft/ft_strstr.o: include/libft.h
libft/ft_atoi.o: include/libft.h
libft/ft_isalnum.o: include/libft.h
libft/ft_memalloc.o: include/libft.h
libft/ft_memdel.o: include/libft.h
libft/ft_strnew.o: include/libft.h
libft/ft_strdel.o: include/libft.h
libft/ft_strclr.o: include/libft.h
libft/ft_strmap.o: include/libft.h
libft/ft_strmapi.o: include/libft.h
libft/ft_strequ.o: include/libft.h
libft/ft_strnequ.o: include/libft.h
libft/ft_strsub.o: include/libft.h
libft/ft_strjoin.o: include/libft.h
libft/ft_strtrim.o: include/libft.h
libft/ft_strsplit.o: include/libft.h
libft/ft_itoa.o: include/libft.h
libft/ft_putstr.o: include/libft.h
libft/ft_putendl.o: include/libft.h
libft/ft_putnbr.o: include/libft.h
libft/ft_putstr_fd.o: include/libft.h
libft/ft_putendl_fd.o: include/libft.h
libft/ft_putnbr_fd.o: include/libft.h
libft/ft_lstnew.o: include/libft.h
libft/ft_lstdelone.o: include/libft.h
libft/ft_lstdel.o: include/libft.h
libft/ft_lstadd.o: include/libft.h
libft/ft_lstiter.o: include/libft.h
libft/ft_lstmap.o: include/libft.h
libft/ft_lstreverse.o: include/libft.h
libft/ft_lstpushback.o: include/libft.h
libft/ft_lstsize.o: include/libft.h
libft/ft_lstpop.o: include/libft.h
