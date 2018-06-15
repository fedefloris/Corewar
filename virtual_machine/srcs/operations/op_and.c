/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/15 02:35:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				get_value(t_vm *vm, t_process *ps, unsigned char encoded, int *parameter, int pair)//make static or move
{
	int				value;

	value = 0;
	if (decode_byte(encoded, pair) == REG_CODE)
		value = ps->r[*parameter];
	if (decode_byte(encoded, pair) == DIR_CODE)
		;
	if (decode_byte(encoded, pair) == IND_CODE)
		value = vm->memory[ps->pc + *parameter];
	*parameter = value;
}

void				op_and(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;
	int				p3;

	printf("Inside op_and\n");//
	printf("pc_tmp %d\n", ps->pc_tmp);
	printf("pc     %d\n\n", ps->pc);

	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];

	calc_bytes(encoded, 1, &bytes);
	printf("bytes 1 %d\n", bytes);
	get_next_bytes(vm, ps, &p1, bytes);
	printf("BYTE:   %x\n", p1);
	get_value(vm, ps, encoded, &p1, 1);
	printf("BYTE:   %d\n", p1);
	printf("R1:   %d\n", ps->r[1]);
	printf("pc_tmp %d\n\n", ps->pc_tmp);

	calc_bytes(encoded, 2, &bytes);
	printf("bytes 2 %d\n", bytes);
	get_next_bytes(vm, ps, &p2, bytes);
	printf("BYTE:   %x\n", p2);
	printf("pc_tmp %d\n\n", ps->pc_tmp);

	calc_bytes(encoded, 3, &bytes);
	printf("bytes 3 %d\n", bytes);
	get_next_bytes(vm, ps, &p3, bytes);
	printf("BYTE:   %x\n", p3);
	printf("pc_tmp %d\n\n", ps->pc_tmp);

	ps->r[p3] = p1 & p2;
	printf("RESULT: %d\n\n", p3);
	if (ps->r[p3])
		ps->carry = 1;
	ps->carry = 1;
	iterate_pc(ps);
	printf("Leaving op_and\n\n");//
}
