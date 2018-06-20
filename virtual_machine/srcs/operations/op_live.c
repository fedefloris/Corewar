/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:45:42 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_process	*get_ps(t_vm *vm, int player_number)
{
	t_process		*ps;

	ps = vm->process;
	while (ps)
	{
		if (ps->number == player_number)
			return (ps);
		ps = ps->next;
	}
	return (NULL);
}

void				op_live(t_vm *vm, t_process *ps)
{
	int				player_number;
	t_process		*ps_live;

	ft_printf("Inside op_live\n");
	get_next_bytes(vm, ps, &player_number, 4);
	ft_printf("Player-nbr: %d, %d\n", ps->number, player_number);
	ft_putnstr(vm->memory, MEM_SIZE);
	ft_putchar('\n');
	if ((ps_live = get_ps(vm, player_number)))
	{
		vm->live_calls++;
		ps->live_calls++;
		vm->last_live = player_number;
		vm->last_name = ps_live->name;
		ft_printf("A process shows that player %d (%s) is alive\n",
					vm->last_live, vm->last_name);
	}
	iterate_pc(ps);
}
