/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dead_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:16:27 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/23 09:37:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void	remove_dead_process(t_vm *vm, t_process **ps, t_process *prev)
{
	if (!prev)
	{
		vm->process = (*ps)->next;
		ft_memdel((void*)ps);
		*ps = vm->process;
	}
	else
	{
		prev->next = (*ps)->next;
		ft_memdel((void*)ps);
		*ps = prev->next;
	}
}

void		remove_dead_processes(t_vm *vm)
{
	t_process	*prev;
	t_process	*ps;

	prev = NULL;
	ps = vm->process;
	while (ps)
	{
		if (ps->live_calls == 0)
		{
			ft_printf("Process n.%d didn't call live\n", ps->number);
			remove_dead_process(vm, &ps, prev);
			if (vm->debug && vm->debug <= vm->tot_cycle)
				system("say Death reported");
		}
		else
		{
			ps->live_calls = 0;
			prev = ps;
			ps = ps->next;
		}
	}
}
