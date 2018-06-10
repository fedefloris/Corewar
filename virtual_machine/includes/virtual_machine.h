/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:58:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/10 21:43:52 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# define SIZE_OF_BUFF	64

# include				"libft.h"
# include 				"op.h"
# include 				<stdio.h>//Remove

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
	int					number;

	uintmax_t			r[REG_NUMBER + 1];
	unsigned long		pc;
	char				carry;

	struct s_byte_code	*byte_code;

	struct s_champ		*next;
}						t_champ;

typedef struct			s_process
{
	int					number;
	int					live_called;
	uintmax_t			r[REG_NUMBER + 1];
	unsigned long		pc;
	char				carry;
	struct s_process	*next_sub;
	struct s_process	*next;
}						t_process;

typedef struct			s_vm
{
	char				**argv;
	int					argc;
	int					cycle;
	int					dump;

	struct s_name		*name;
	struct s_champ		*champ;
	struct s_process	*process;
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

t_op					op_tab[17];

typedef void			(*t_op_code)(t_vm *vm);

void					test_print(t_vm *vm);//Remove

void					usage(t_vm *vm, int i);

void					error_exit(t_vm *vm, char *string);
void					free_virtual_machine(t_vm *vm);

void					virtual_machine(t_vm *vm);

void					parse_handler(t_vm *vm);
void					parse_options(t_vm *vm);
void					parse_create_champ(t_vm *vm);
void					parse_read_champ(t_vm *vm);

void					do_op(t_vm *vm, int op_code);

void					op_live(t_vm *vm);
void					op_ld(t_vm *vm);
void					op_st(t_vm *vm);
void					op_add(t_vm *vm);
void					op_sub(t_vm *vm);
void					op_and(t_vm *vm);
void					op_or(t_vm *vm);
void					op_xor(t_vm *vm);
void					op_zjmp(t_vm *vm);
void					op_ldi(t_vm *vm);
void					op_sti(t_vm *vm);
void					op_fork(t_vm *vm);
void					op_lld(t_vm *vm);
void					op_lldi(t_vm *vm);
void					op_lfork(t_vm *vm);
void					op_aff(t_vm *vm);

#endif
