# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 21:26:09 by minjeeki          #+#    #+#              #
#    Updated: 2024/04/29 05:07:22 by minjeeki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS := $(wildcard ./src/*.c)
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Werror -Wextra -Wall
INC = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)
LIB = -L $(LIB_DIR) -l ft

LIB_DIR = libft/
INC_DIR = includes/
SRC_DIR = srcs/
OBJ_DIR = objs/

COMMON_SRCS = parsing.c utils_parsing.c normalize.c utils_normalize.c stack.c utils_stack.c commands.c radix_sort.c simple_sort.c self_debug.c
PSWAP_SRCS = push_swap.c utils.c $(COMMON_SRCS)

PSWAP_OBJS = $(addprefix $(OBJ_DIR), $(PSWAP_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(PSWAP_OBJS)
	@make -C $(LIB_DIR) --silent
	$(CC) $(CFLAGS) $(PSWAP_OBJS) -o $@ $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAG) -c $< -o $@ $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re