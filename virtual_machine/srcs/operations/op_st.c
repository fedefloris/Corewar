/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:58 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:39:37 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			load(t_vm *vm, t_process *ps, int p1, int p2)
{
	vm->memory[p2 + 0] = (p1 >> 24);
	vm->memory[p2 + 1] = (p1 >> 16) & 0xFF;
	vm->memory[p2 + 2] = (p1 >> 8) & 0xFF;
	vm->memory[p2 + 3] = p1 & 0xFF;
}

void				op_st(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;

	ft_printf("Inside op_st\n");
	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];
	calc_bytes(encoded, 1, &bytes);
	get_next_bytes(vm, ps, &p1, bytes);
	get_value(vm, ps, decode_byte(encoded, 1), &p1);
	calc_bytes(encoded, 2, &bytes);
	get_next_bytes(vm, ps, &p2, bytes);
	if (decode_byte(encoded, 2) == IND_CODE)
	{
		get_address(ps, p2 % IDX_MOD, &p2);
		load(vm, ps, p1, p2);
	}
	else if (decode_byte(encoded, 2) == REG_CODE)
		ps->r[get_r(p2)] = p1;
	iterate_pc(ps);
}
