# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 22:13:44 by minjeeki          #+#    #+#              #
#    Updated: 2024/04/27 22:13:45 by minjeeki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
INC = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)
LIB = -L $(LIB_DIR) -l ft

PSWAP_NAME = push_swap
CHKER_NAME = checker
NAME := $(PSWAP_NAME)

LIB_DIR = libft/
INC_DIR = includes/
SRC_DIR = srcs/
OBJ_DIR = objs/

#== Define srcs ==#
COMMON_SRCS = choose_best_elem.c pb_and_set_b.c simple_sort.c do_op.c op.c get_values.c stack_utils.c
PSWAP_SRCS = push_swap.c $(COMMON_SRCS)
CHKER_SRCS = checker.c $(COMMON_SRCS)

#== Define objs ==#
PSWAP_OBJS = $(addprefix $(OBJ_DIR), $(PSWAP_SRCS:.c=.o))
CHKER_OBJS = $(addprefix $(OBJ_DIR), $(CHKER_SRCS:.c=.o))

#== For bonus ==#
ifdef WITH_BONUS
	NAME := $(CHKER_NAME)
endif

#== Rules ==#
all: $(NAME)

bonus:
	@make WITH_BONUS=1 all

$(PSWAP_NAME): $(PSWAP_OBJS)
	@make -C $(LIB_DIR) --silent
	$(CC) $(CFLAGS) $(PSWAP_OBJS) -o $@ $(LIB)
	@echo "\033[32m[$(PSWAP_NAME)]: compiled\033[0m"

$(CHKER_NAME): $(CHKER_OBJS)
	@make -C $(LIB_DIR) --silent
	$(CC) $(CFLAGS) $(CHKER_OBJS) -o $@ $(LIB)
	@echo "\033[32m[$(CHKER_NAME)]: compiled\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@$(CC) $(CFLAG) -c $< -o $@ $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m[ ✔ ] clean\033[0m"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(PSWAP_NAME) $(CHKER_NAME)
	@echo "\033[31m[ ✔ ] fclean\033[0m"

re: fclean all

.PHONY: all clean fclean re