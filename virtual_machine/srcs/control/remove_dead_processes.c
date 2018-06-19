/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dead_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:16:27 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/19 15:26:34 by ffloris          ###   ########.fr       */
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
			{
				vm->process = ps->next;
				ft_memdel((void*)&ps);
				ps = vm->process;
			}
			else
			{
				prev_ps->next = ps->next;
				ft_memdel((void*)&ps);
				ps = prev_ps->next;
			}
		}
		else
		{
			ps->live_calls = 0;
			prev_ps = ps;
			ps = ps->next;
		}
	}
}
