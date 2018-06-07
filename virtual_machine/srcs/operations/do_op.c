/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:44:29 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/07 21:10:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_op_code		get_op(int op_code)
{
	static t_op_code	table[17];
	int					i;

	i = 0;
	if (op_code < 1 || op_code > 16)
		return (NULL);
	table[0x00] = NULL;
	table[0x01] = &op_live;
	table[0x02] = &op_ld;
	table[0x03] = &op_st;
	table[0x04] = &op_add;
	table[0x05] = &op_sub;
	table[0x06] = &op_and;
	table[0x07] = &op_or;
	table[0x08] = &op_xor;
	table[0x09] = &op_zjmp;
	table[0x0a] = &op_ldi;
	table[0x0b] = &op_sti;
	table[0x0c] = &op_fork;
	table[0x0d] = &op_lld;
	table[0x0e] = &op_lldi;
	table[0x0f] = &op_lfork;
	table[0x10] = &op_aff;
	return (table[op_code]);
}

void				do_op(t_vm *vm)
{
	t_op_code		op_code;

	//get op code to pass to below function.
	if (!(op_code = get_op(4)))
		error_exit(vm);//invalid op code
	op_code(vm);
}
