/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:25:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/17 15:25:53 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			setup_ops(t_op_code *table)
{
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
}

static t_op_code	get_op(long op_code)
{
	static t_op_code	table[7237484];

	if (op_code < 1 || op_code > 7237483)
		return (NULL);
	if (!table[1764])
		setup_ops(table);
	return (table[op_code]);
}

static long			hash_name(char *name)
{
	long			hash;

	if (!name)
		return (0);
	hash = 0;
	while (*name)
	{
		hash = hash << 4;
		hash |= *name;
		name++;
	}
	return (hash);
}

void				save_op(t_process *ps, int op_code)
{
	t_op			*seek;

	seek = g_op_tab;
	while (seek->op_code && seek->op_code != op_code)
		seek++;
	if (!(ps->op = get_op(hash_name(seek->name))))
	{
		modify_pc(ps, 1);
		ps->sleep_cycles = 1;
	}
	else
		ps->sleep_cycles = seek->nb_cycles - 1;
}
