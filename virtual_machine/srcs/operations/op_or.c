/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:48 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/15 13:25:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_or(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;
	int				p3;

	ft_printf("Inside op_or\n");//
	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];
	calc_bytes(encoded, 1, &bytes);
	get_next_bytes(vm, ps, &p1, bytes);
	get_value(vm, ps, decode_byte(encoded, 1), &p1);
	calc_bytes(encoded, 2, &bytes);
	get_next_bytes(vm, ps, &p2, bytes);
	get_value(vm, ps, decode_byte(encoded, 2), &p1);
	get_next_bytes(vm, ps, &p3, 1);
	ps->r[p3] = p1 | p2;
	modify_carry(ps, ps->r[p3]);
	iterate_pc(ps);
}
