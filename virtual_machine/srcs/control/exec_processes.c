/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:49 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/15 02:34:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void		exec_process(t_vm *vm, t_process *ps)
{
	if (ps->op)
	{
		ft_printf("Exec_ps %d | pc  %d | carry %d | op_code %d\n",
			ps->number, ps->pc, ps->carry, (int)vm->memory[ps->pc]);
		ps->op(vm, ps);
		ps->op = NULL;
	}
	ps->pc_tmp = ps->pc;
	save_op(ps, (int)vm->memory[ps->pc]);
}

void			exec_processes(t_vm *vm)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		if (!ps->sleep_cycles)
			exec_process(vm, ps);
		else
			ps->sleep_cycles--;
		ps = ps->next;
	}
}
