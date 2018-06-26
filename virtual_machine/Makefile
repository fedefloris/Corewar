# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/06/21 16:56:46 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

GCC_FLAGS = -Werror -Wextra -Wall

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS_INCLUDES_DIR = includes

LIBFT_DIR = ../libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR = $(LIBFT_DIR)/includes

SHARED_DIR = ../shared
SHARED_INCLUDES_DIR = $(SHARED_DIR)/includes

INCLUDE_DIRS = -I $(SRCS_INCLUDES_DIR) -I $(LIBFT_INCLUDES_DIR) \
	-I $(SHARED_INCLUDES_DIR)

INCLUDES_FILES = virtual_machine
HEADERS = $(addsuffix .h, $(patsubst %, $(SRCS_INCLUDES_DIR)/%, $(INCLUDES_FILES)))
HEADERS += $(SHARED_INCLUDES_DIR)/op.h

CONTROL_FILES = dump_memory duplicate_process exec_process exec_processes \
	add_op_to_queue exec_ops_queue exec_vm insert_sub_process \
	load_process load_processes remove_dead_processes

OP_TOOLS_FILES = calc_bytes decode_byte get_address get_next_bytes \
	get_r get_reg_value get_value iterate_pc load_bytes \
	modify_carry modify_pc modify_pc_tmp return_address

OPERATIONS_FILES = op op_add op_aff op_and op_fork op_ld op_ldi \
	op_lfork op_live op_lld op_lldi op_or op_st op_sti op_sub \
	op_xor op_zjmp save_op

PARSE_FILES = parse_bytes parse_count_champions parse_create_champ \
	parse_handler parse_options parse_read_champ parse_aff \
	parse_check_dump_debug parse_debug parse_dump parse_num

SYSTEM_FILES = config_vm display_usage error_exit free_champs free_names \
	free_processes free_ops_queue free_vm main

CONTROL_OBJS = $(addsuffix .o, $(CONTROL_FILES))
OP_TOOLS_OBJS = $(addsuffix .o, $(OP_TOOLS_FILES))
OPERATIONS_OBJS = $(addsuffix .o, $(OPERATIONS_FILES))
PARSE_OBJS = $(addsuffix .o, $(PARSE_FILES))
SYSTEM_OBJS = $(addsuffix .o, $(SYSTEM_FILES))

CONTROL_OBJS_DIR = $(OBJS_DIR)/control
OP_TOOLS_OBJS_DIR = $(OBJS_DIR)/op_tools
OPERATIONS_OBJS_DIR = $(OBJS_DIR)/operations
PARSE_OBJS_DIR = $(OBJS_DIR)/parse
SYSTEM_OBJS_DIR = $(OBJS_DIR)/system
OBJS_DIRS = $(CONTROL_OBJS_DIR) $(OP_TOOLS_OBJS_DIR) \
	$(OPERATIONS_OBJS_DIR) $(PARSE_OBJS_DIR) $(SYSTEM_OBJS_DIR)

OBJS = $(patsubst %, $(CONTROL_OBJS_DIR)/%, $(CONTROL_OBJS))
OBJS += $(patsubst %, $(OP_TOOLS_OBJS_DIR)/%, $(OP_TOOLS_OBJS))
OBJS += $(patsubst %, $(OPERATIONS_OBJS_DIR)/%, $(OPERATIONS_OBJS))
OBJS += $(patsubst %, $(PARSE_OBJS_DIR)/%, $(PARSE_OBJS))
OBJS += $(patsubst %, $(SYSTEM_OBJS_DIR)/%, $(SYSTEM_OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"

all: $(NAME)

norm:
	@norminette $(SRCS_INCLUDES_DIR) $(SRCS_DIR)

$(LIBFT_FILE):
	@echo "Libft:" $(GREEN_COLOR) Compiling Libft $(DEFAULT_COLOR)
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_FILE) $(OBJS_DIRS) $(OBJS)
	@echo "Corewar:" $(GREEN_COLOR) $(NAME) $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) $(OBJS) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  $(HEADERS)
	@echo "Corewar:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all norm clean fclean re
