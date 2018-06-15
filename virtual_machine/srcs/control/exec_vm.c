/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:52:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/15 01:14:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

// static void	kill_processes(t_vm *vm)
// {
// 	t_process	*ps;

// 	ps = vm->process;
// 	while (ps)
// 	{
// 		if (ps->live_calls == 0)
// 		{
// 			ft_printf("Process n.%d didn't call live\n", ps->number);
// 		}
// 		else
// 			ps->live_calls = 0;
// 		ps = ps->next;
// 	}
// }

void		exec_vm(t_vm *vm)
{
	load_processes(vm);
	while (1)
	{
		if (!vm->process)
			break ;
		exec_processes(vm);
		vm->cycle++;
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			// if one process didn't call live delete it (bonus sound)
			ft_printf("Every CYCLE_TO_DIE cycles: cycles = %d\n", vm->cycle);
			// kill_processes(vm);
		}
		if (vm->live_calls > 0 && vm->live_calls % NBR_LIVE == 0 &&
			(vm->cycle_to_die -= CYCLE_DELTA) <= 0)
			break ;
		usleep(1000);
		// If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease it.
	}
	// The winner is the last player reported to be “alive”
	ft_printf("Player %d (player-name) won", vm->last_live);
}
