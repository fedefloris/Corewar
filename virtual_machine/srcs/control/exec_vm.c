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
	while (vm->process && vm->cycle_to_die > 0)
	{
		exec_processes(vm);
		if (vm->cycle == vm->cycle_to_die)
		{
			ft_printf("Every CYCLE_TO_DIE cycles: cycles = %d\n", vm->cycle);
			remove_dead_processes(vm);
			vm->checkups++;
			if (vm->checkups == MAX_CHECKS || vm->live_calls >= NBR_LIVE)
			{
				ft_printf("checkups: %d | live_calls = %d\n", vm->checkups, vm->live_calls);
				vm->cycle_to_die -= CYCLE_DELTA;
				vm->checkups = 0;
			}
			vm->cycle = 0;
			vm->live_calls = 0;
		}
		ft_printf("Cycle %d | cycle_to_die %d | tot_cycle %d | live_calls %d\n", vm->cycle, vm->cycle_to_die, vm->tot_cycle, vm->live_calls);
		vm->cycle++;
		vm->tot_cycle++;
	}
	ft_printf("Player %d (%s) won\n", vm->last_live, vm->last_name);
}
