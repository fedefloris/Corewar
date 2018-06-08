/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:44:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/08 10:46:57 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_op_code	get_op(long op_code)
{
	static t_op_code	table[7237484];

	if (op_code < 1 || op_code > 7237483)
		return (NULL);
	table[0] = NULL;
	table[454501] = &op_live;
	table[1764] = &op_ld;
	table[1908] = &op_st;
	table[26468] = &op_add;
	table[30578] = &op_sub;
	table[26596] = &op_and;
	table[1778] = &op_or;
	table[32498] = &op_xor;
	table[519920] = &op_zjmp;
	table[28265] = &op_ldi;
	table[30569] = &op_sti;
	table[421739] = &op_fork;
	table[28388] = &op_lld;
	table[454249] = &op_lldi;
	table[7237483] = &op_lfork;
	table[26470] = &op_aff;
	return (table[op_code]);
}

static long			hash_name(char *name)
{
	long			hash;

	hash = 0;
	while (*name)
	{
		hash = hash << 4;
		hash |= *name;
		name++;
	}
	return (hash);
}

void				do_op(t_vm *vm, int op_code)
{
	t_op_code		op_function;
	t_op			*seek;

	seek = op_tab;
	while (seek->op_code && seek->op_code != op_code)
		seek++;
	if (!(op_function = get_op(hash_name(seek->name))))
		error_exit(vm);//invalid op code
	op_function(vm);
}
