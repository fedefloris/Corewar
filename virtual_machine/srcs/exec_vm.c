/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:52:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/10 16:52:56 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			exec_processes(t_vm *vm)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		ft_printf("Executing process %d\n", ps->number);
		ps = ps->next;
	}
}

void				exec_vm(t_vm *vm)
{
	load_processes(vm);
/*	while (1)
	{
		if (!vm->process)
			break ;
		exec_processes(vm);
		vm->cycle++;
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			// if one process didn't call live delete it
			ft_printf("Every CYCLE_TO_DIE cycles\n");
		}
		if (vm->live_calls % NBR_LIVE == 0 &&
			(vm->cycle_to_die -= CYCLE_DELTA) <= 0)
			break ;

		// If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease it.
	}
	// The winner is the last player reported to be “alive”
	*/
}
