/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:54:49 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/14 23:18:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void		exec_process(t_vm *vm, t_process *ps)
{
	ft_printf("Executing process %d, pc => %d\n", ps->number, ps->pc);
	ps->tmp_pc = ps->pc;
	do_op(vm, ps, (int) vm->memory[ps->pc]);
}

void			exec_processes(t_vm *vm)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		exec_process(vm, ps);
		ps = ps->next;
	}
}
