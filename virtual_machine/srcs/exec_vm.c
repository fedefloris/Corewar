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
		}
		if (vm->live_calls > 0 && vm->live_calls % NBR_LIVE == 0 &&
			(vm->cycle_to_die -= CYCLE_DELTA) <= 0)
			break ;
		sleep(1);
		// If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease it.
	}
	// The winner is the last player reported to be “alive”
	// ft_printf("Player %s (%s) won", vm->last_live,
	// 						vm->live_hash[vm->last_live]);
}
