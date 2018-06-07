/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:58:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 18:39:57 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# define SIZE_OF_BUFF	64

# include "libft.h"
# include "op.h"
# include <stdio.h>//Remove

typedef struct			s_byte_code
{
	char				byte;
	struct s_byte_code	*next;
}						t_byte_code;

typedef struct			s_file
{
	char				*file_name;
	struct s_byte_code	*byte_code;
	struct s_file		*next;
}						t_file;

typedef struct			s_vm
{
	char				**argv;
	int					argc;

	struct s_file		*file;
}						t_vm;

typedef void			(*t_op)(t_vm *vm);

void					test_print(t_vm *vm);//Remove

void					usage(t_vm *vm, int i);

void					error_exit(t_vm *vm);
void					free_virtual_machine(t_vm *vm);

void					virtual_machine(t_vm *vm);

void					parse_handler(t_vm *vm);
void					parse_create_file(t_vm *vm);
void					parse_read_file(t_vm *vm);

void					do_op(t_vm *vm);

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
