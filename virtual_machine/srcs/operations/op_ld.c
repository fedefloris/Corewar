/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:54 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:11:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_ld(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;

	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];
	calc_bytes(encoded, 1, &bytes);
	get_next_bytes(vm, ps, &p1, bytes);
	get_next_bytes(vm, ps, &p2, 1);
	if (decode_byte(encoded, 1) == DIR_CODE)
		ps->r[get_r(p2)] = p1;
	else
	{
		get_address(ps, p1 % IDX_MOD, &p1);
		load_bytes(vm, ps, p2, p1);
	}
	modify_carry(ps, ps->r[get_r(p2)]);
	iterate_pc(ps);
}
