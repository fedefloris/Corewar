/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:58:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/18 12:22:29 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include "libft.h"
# include "op.h"
# define SIZE_OF_BUFF	64
# define CLEAR			"\x1b[H\x1b[2J"
# define B_RED			"\x1b[1m\x1b[31m"
# define B_GREEN		"\x1b[1m\x1b[32m"
# define B_YELLOW		"\x1b[1m\x1b[33m"
# define B_BLUE			"\x1b[1m\x1b[34m"
# define B_PINK			"\x1b[1m\x1b[35m"
# define B_CYAN    		"\x1b[1m\x1b[36m"
# define B_WHITE   		"\x1b[1m\x1b[37m"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PINK			"\x1b[35m"
# define CYAN    		"\x1b[36m"
# define WHITE   		"\x1b[37m"
# define RESET   		"\x1b[0m"

typedef struct			s_name
{
	int					num;
	int					pos;
	struct s_name		*next;
}						t_name;
typedef struct			s_byte_code
{
	char				byte;
	struct s_byte_code	*next;
}						t_byte_code;
typedef struct			s_champ
{
	char				*file_name;
	int					prog_size;
	int					number;
	char				*name;
	char				*bytes;
	t_byte_code			*byte_code;
	struct s_champ		*next;
}						t_champ;
typedef struct			s_process
{
	char				*name;
	int					number;
	intmax_t			r[256];
	int					pc;
	int					pc_tmp;
	char				carry;
	int					live_calls;
	int					sleep_cycles;
	void				(*op)();
	struct s_process	*next;
}						t_process;
typedef struct			s_vm
{
	char				**argv;
	int					argc;
	int					dump;
	int					aff;
	int					affd;
	int					affx;
	int					affx2;
	int					cycle;
	int					tot_cycle;
	int					cycle_to_die;
	int					checkups;
	int					live_calls;
	int					last_live;
	char				*last_name;
	char				memory[MEM_SIZE];
	t_name				*name;
	t_champ				*champ;
	t_process			*process;
}						t_vm;
typedef struct			s_op
{
	char				*name;
	int					params_quantity;
	int					param_type[4];
	int					op_code;
	int					nb_cycles;
	char				*description;
	int					has_pcode;
	int					has_idx;
}						t_op;

t_op					g_op_tab[17];

typedef void			(*t_op_code)(t_vm *vm, t_process *ps);

void					display_usage();
void					error_exit(t_vm *vm, char *string);
void					config_vm(t_vm *vm, int argc, char **argv);
void					free_vm(t_vm *vm);
void					free_names(t_name *names);
void					free_champs(t_champ *champs);
void					free_processes(t_process *processes);
void					parse_handler(t_vm *vm);
void					parse_options(t_vm *vm);
void					parse_create_champ(t_vm *vm);
void					parse_read_champ(t_vm *vm);
void					parse_bytes(t_vm *vm);
void					parse_count_champions(t_vm *vm);
void					exec_vm(t_vm *vm);
void					load_processes(t_vm *vm);
void					load_process(t_vm *vm, t_champ *champ, size_t pos);
void					exec_processes(t_vm *vm);
void					duplicate_process(t_vm *vm, t_process *ps,
													t_process **new_ps);
void					insert_sub_process(t_vm *vm, t_process *new_ps);
void					remove_dead_processes(t_vm *vm);
void					modify_pc(t_process *process, int modift);
void					modify_pc_tmp(t_process *process, int modify);
void					iterate_pc(t_process *ps);
void					get_address(t_process *ps, int modify, int *address);
int						return_address(t_process *ps, int modify);
char					decode_byte(unsigned char encoded, int pair);
void					calc_bytes(unsigned char encoded, int pair, int *bytes);
void					get_next_bytes(t_vm *vm, t_process *ps, int *value,
																int n);
void					get_value(t_vm *vm, t_process *ps,
									unsigned char encoded, int *parameter);
void					get_reg_value(t_vm *vm, t_process *ps,
									unsigned char encoded, int *parameter);
void					modify_carry(t_process *ps, int value);
void					save_op(t_vm *vm, t_process *ps, int op_code);
void					op_live(t_vm *vm, t_process *ps);
void					op_ld(t_vm *vm, t_process *ps);
void					op_st(t_vm *vm, t_process *ps);
void					op_add(t_vm *vm, t_process *ps);
void					op_sub(t_vm *vm, t_process *ps);
void					op_and(t_vm *vm, t_process *ps);
void					op_or(t_vm *vm, t_process *ps);
void					op_xor(t_vm *vm, t_process *ps);
void					op_zjmp(t_vm *vm, t_process *ps);
void					op_ldi(t_vm *vm, t_process *ps);
void					op_sti(t_vm *vm, t_process *ps);
void					op_fork(t_vm *vm, t_process *ps);
void					op_lld(t_vm *vm, t_process *ps);
void					op_lldi(t_vm *vm, t_process *ps);
void					op_lfork(t_vm *vm, t_process *ps);
void					op_aff(t_vm *vm, t_process *ps);
#endif
