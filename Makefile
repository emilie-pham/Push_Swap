# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 09:54:19 by epham             #+#    #+#              #
#    Updated: 2019/07/08 12:24:36 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean
.PHONY: fclean
.PHONY: re

NAME_CHECKER	:= checker
NAME_PUSH_SWAP	:= push_swap

NAME			:= $(NAME_CHECKER) $(NAME_PUSH_SWAP)

VPATH			:= ./srcs/ ./objects/checker/ ./objects/push_swap/ ./includes/

CC				?= gcc
FLAGS			= -Wall -Wextra -Werror
LIB				:= libft/libft.a
INCLUDES		:= -I includes/ -I libft/includes/

SRCS_PATH		= ./srcs/

OBJS_CHECKER_PATH	:= ./objects/checker/
OBJS_PUSH_SWAP_PATH	:= ./objects/push_swap/

SRCS_NAME		:=	algorithms.c \
					check_error.c \
					operations.c \
					optimization.c \
					parser.c \
					pibon_operations_a.c \
					pibon_operations_b.c \
					push_back.c \
					push_to.c \
					sort_a.c \
					sort_b.c \
					sort_random.c \
					utils.c \
					utils_push_back.c \
					utils_push_to.c \
					visual.c

SRCS_CHECKER_NAME := checker.c
SRCS_CHECKER_NAME += $(SRCS_NAME)

SRCS_PUSH_SWAP_NAME := push_swap.c
SRCS_PUSH_SWAP_NAME += $(SRCS_NAME)

OBJS_CHECKER_NAME := $(SRCS_CHECKER_NAME:.c=.o)
OBJS_PUSH_SWAP_NAME := $(SRCS_PUSH_SWAP_NAME:.c=.o)

SRCS_CHECKER := $(patsubst %,$(SRCS_PATH)%,$(SRCS_CHECKER_NAME))
SRCS_PUSH_SWAP := $(patsubst %,$(SRCS_PATH)%,$(SRCS_PUSH_SWAP_NAME))

OBJS_CHECKER := $(patsubst %,$(OBJS_CHECKER_PATH)%,$(OBJS_CHECKER_NAME))
OBJS_PUSH_SWAP := $(patsubst %,$(OBJS_PUSH_SWAP_PATH)%,$(OBJS_PUSH_SWAP_NAME))

all: $(NAME)

$(OBJS_CHECKER_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(NAME_CHECKER): $(OBJS_CHECKER)
	@$(MAKE) -C libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
	@echo [Checker Compiled]

$(OBJS_PUSH_SWAP_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	
$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP)
	@$(MAKE) -C libft/
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
	@echo [Push Swap Compiled]

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS_CHECKER)
	@rm -f $(OBJS_PUSH_SWAP)
	@echo [Checker Objects Removed]
	@echo [Push Swap Objects Removed]

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME_CHECKER)
	@rm -f $(NAME_PUSH_SWAP)
	@echo [Checker Removed]
	@echo [Push Swap Removed]

re: fclean all
