# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 21:26:09 by minjeeki          #+#    #+#              #
#    Updated: 2024/04/20 21:40:46 by minjeeki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c before_sort.c stack.c stack_commands.c util.c
#		quick_sort.c optimization.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar rcs $@ $^

.c.o:
		${CC} ${CFLAGS} -c -o $@ $<

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re