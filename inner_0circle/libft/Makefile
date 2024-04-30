# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:17:49 by minjeeki          #+#    #+#              #
#    Updated: 2023/10/28 21:37:59 by minjeeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	   ft_strnstr.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_split.c \
	   ft_memcpy.c ft_bzero.c ft_memset.c ft_memchr.c ft_memcmp.c \
	   ft_memmove.c ft_atoi.c ft_strdup.c ft_calloc.c ft_strtrim.c \
	   ft_substr.c ft_strjoin.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = ${SRCS:.c=.o}
BSRCS = ft_lstnew.c
BOBJS = ${BSRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $@ $^

.c.o:
	${CC} ${CFLAGS} -c -o $@ $<

# bonus: ${NAME} ${BOBJS}
#	ar rcs $< $^
	
clean:
	rm -f ${OBJS} ${BOBJS}

fclean: clean
	rm -f ${NAME} ${bonus}

re : fclean all

.PHONY : all clean fclean re
