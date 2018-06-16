/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dead_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:16:27 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/15 17:16:28 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		remove_dead_processes(t_vm *vm)
{
	t_process	*prev_ps;
	t_process	*ps;

	prev_ps = NULL;
	ps = vm->process;
	while (ps)
	{
		if (ps->live_calls == 0)
		{
			ft_printf("Process n.%d didn't call live\n", ps->number);
			if (!prev_ps)
				vm->process = ps->next;
			else
				prev_ps->next = ps->next;
			//FREE PROCESS => ps
		}
		else
			ps->live_calls = 0;
		prev_ps = ps;
		ps = ps->next;
	}
}