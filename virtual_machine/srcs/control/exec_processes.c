/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:49 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/22 00:39:40 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void			exec_processes(t_vm *vm)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		if (!ps->sleep_cycles)
		{
			add_op_to_queue(vm, ps);
			if (!ps->op)
				exec_process(vm, ps);
		}
		else
			ps->sleep_cycles--;
		ps = ps->next;
	}
	exec_ops_queue(vm);
}
