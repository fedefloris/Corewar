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

void		exec_vm(t_vm *vm)
{
	load_processes(vm);
	while (1)
	{
		if (!vm->process || vm->cycle_to_die <= 0)
			break ;
		exec_processes(vm);
		vm->cycle++;
		ft_printf("Cycle %d | cycle_to_die %d | live_calls %d\n",
			vm->cycle, vm->cycle_to_die, vm->live_calls);
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			ft_printf("Every CYCLE_TO_DIE cycles: cycles = %d\n", vm->cycle);
			remove_dead_processes(vm);
		}
		if (vm->live_calls > 0 && vm->live_calls % NBR_LIVE == 0)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->live_calls = 0;
		}
		usleep(100000);
		// If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease it.
	}
	ft_printf("Player %d (%s) won\n", vm->last_live, vm->last_name);
}
