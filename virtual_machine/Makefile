# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/05/03 10:16:27 by ffloris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

GCC_FLAGS = -Werror -Wextra -Wall

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS_INCLUDES_DIR = includes/

LIBFT_DIR = ../libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR = $(LIBFT_DIR)/includes/
INCLUDE_DIRS = -I$(SRCS_INCLUDES_DIR) -I$(LIBFT_INCLUDES_DIR)

FILES = main

OBJS_WITH_DIR = $(patsubst %, $(OBJS_DIR)/%.o, $(FILES))
SRCS = $(addsuffix .c, $(FILES))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"

all: $(NAME)

norm:
	@norminette $(SRCS_INCLUDES_DIR) $(SRCS_DIR)

$(LIBFT_FILE):
	@echo "Libft:" $(GREEN_COLOR) Compiling Libft $(DEFAULT_COLOR)
	@make -C ../libft

$(NAME): $(LIBFT_FILE) $(OBJS_DIR) $(OBJS_WITH_DIR)
	@echo "Corewar:" $(GREEN_COLOR) $(NAME) $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) $(OBJS_WITH_DIR) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Corewar:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all norm clean fclean re
