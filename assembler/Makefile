# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/06/16 18:31:29 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

GCC_FLAGS = -Werror -Wextra -Wall

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS_INCLUDES_DIR = includes/

LIBFT_DIR = ../libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR = $(LIBFT_DIR)/includes/
INCLUDE_DIRS = -I$(SRCS_INCLUDES_DIR) -I$(LIBFT_INCLUDES_DIR)

FILES = main ft_input ft_inp_tools ft_lst_tools ft_line_parsing ft_free \
		ft_error ft_output ft_valid_arg ft_line_producing ft_bytecode \
		ft_bytecode2 op

OBJS_WITH_DIR = $(patsubst %, $(OBJS_DIR)/%.o, $(FILES))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"

all: $(NAME)

norm:
	@norminette $(SRCS_INCLUDES_DIR) $(SRCS_DIR)

$(LIBFT_FILE):
	@echo "Libft:" $(GREEN_COLOR) Compiling Libft $(DEFAULT_COLOR)
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_FILE) $(OBJS_DIR) $(OBJS_WITH_DIR)
	@echo "Asm:" $(GREEN_COLOR) $(NAME) $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) $(OBJS_WITH_DIR) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Asm:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all norm clean fclean re
