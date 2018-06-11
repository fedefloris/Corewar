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

void				exec_vm(t_vm *vm)
{
	load_champions(vm);
/*	while (1)
	{
		if there aren't processes
				break;
		execute every process
		
		vm->cycle++;
		
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			if one process didn't call live delete it
		}
		
		If CYCLE_TO_DIE wasn’t decreased since MAX_CHECKS checkups, decrease it.
		
		if (vm->live_calls % NBR_LIVE == 0 &&
			(vm->cycle_to_die -= CYCLE_DELTA) <= 0)
			break ;
	}
	// The winner is the last player reported to be “alive”
*/
}
