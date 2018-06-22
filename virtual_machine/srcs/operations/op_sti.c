/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:04:08 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:39:50 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			load(t_vm *vm, t_process *ps, int p1, int p3)
{
	int				value;

	value = ps->r[get_r(p1)];
	vm->memory[return_address(ps, p3)] = (value >> 24) & 0xFF;
	vm->memory[return_address(ps, p3 + 1)] = (value >> 16) & 0xFF;
	vm->memory[return_address(ps, p3 + 2)] = (value >> 8) & 0xFF;
	vm->memory[return_address(ps, p3 + 3)] = value & 0xFF;
}

void				op_sti(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;
	int				p3;

	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];
	get_next_bytes(vm, ps, &p1, 1);
	bytes = (decode_byte(encoded, 2) == REG_SIZE) ? 1 : 2;
	get_next_bytes(vm, ps, &p2, bytes);
	get_value(vm, ps, (bytes == 2) ? 2 : 1, &p2);
	bytes = (decode_byte(encoded, 3) == REG_SIZE) ? 1 : 2;
	get_next_bytes(vm, ps, &p3, bytes);
	get_value(vm, ps, (bytes == 2) ? 2 : 1, &p3);
	load(vm, ps, p1, p2 + p3);
	iterate_pc(ps);
}
