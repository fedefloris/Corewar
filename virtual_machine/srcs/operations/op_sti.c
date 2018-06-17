/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:04:08 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/17 02:30:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_sti(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;
	int				p3;

	ft_printf("Inside op_sti\n");
	modify_pc_tmp(ps, 1);
	ft_printf(GREEN);
	ft_printf("R3 was %x\n", ps->r[3]);
	ft_printf(RESET);
	encoded = vm->memory[ps->pc_tmp];
	get_next_bytes(vm, ps, &p1, 1);
	if (decode_byte(encoded, 2) == REG_SIZE)
	{
		get_next_bytes(vm, ps, &p2, 1);
		get_value(vm, ps, REG_SIZE, &p2);
	}
	else
	{
		get_next_bytes(vm, ps, &p2, 2);
		get_value(vm, ps, IND_SIZE, &p2);
	}
	if (decode_byte(encoded, 2) == REG_SIZE)
	{
		get_next_bytes(vm, ps, &p3, 1);
		get_value(vm, ps, REG_SIZE, &p3);
	}
	else
	{
		get_next_bytes(vm, ps, &p3, 2);
		get_value(vm, ps, IND_SIZE, &p3);
	}
	get_address(ps, p2 + p3, &p3);
	vm->memory[p3] = p1;
	iterate_pc(ps);
	ft_printf(YELLOW);
	ft_printf("R3 is %x\n", ps->r[3]);
	ft_printf(RESET);
}
