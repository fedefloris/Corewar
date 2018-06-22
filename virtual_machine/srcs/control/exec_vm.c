/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:52:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/22 14:41:57 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void	dump_control(t_vm *vm)
{
	if (vm->dump == vm->tot_cycle)
		dump_memory(vm, 4, 1);
	if (vm->debug && vm->debug <= vm->tot_cycle)
	{
		if (!(vm->tot_cycle % 20))
			ft_printf(CLEAR);
		ft_printf(CUR_RESET);
		dump_memory(vm, 8, 0);
		usleep(10000);
	}
}

static void	display_result(t_vm *vm)
{
	if (vm->last_live && vm->last_name)
		ft_printf("Player %d (%s) won\n", vm->last_live, vm->last_name);
	else
		ft_printf("There are no winners\n");
}

void		exec_vm(t_vm *vm)
{
	load_processes(vm);
	while (vm->process && vm->cycle_to_die > 0)
	{
		exec_processes(vm);
		if (vm->tot_cycle == CYCLE_TO_DIE)
			vm->cycle = 0;
		if (vm->cycle == vm->cycle_to_die)
		{
			remove_dead_processes(vm);
			vm->checkups++;
			if (vm->checkups == MAX_CHECKS || vm->live_calls >= NBR_LIVE)
			{
				vm->cycle_to_die -= CYCLE_DELTA;
				vm->checkups = 0;
			}
			vm->cycle = 0;
			vm->live_calls = 0;
		}
		dump_control(vm);
		vm->cycle++;
		vm->tot_cycle++;
	}
	display_result(vm);
}
