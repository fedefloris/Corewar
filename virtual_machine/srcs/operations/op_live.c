/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 20:45:39 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_live(t_vm *vm, t_process *ps)
{
	int				player_number;
	int				i;

	player_number = 0;
	i = 0;
	while (i++ < 4)
	{
		modify_pc(ps, 1);
		player_number <<= 8;
		player_number += vm->memory[ps->pc];
	}
	if (vm->live_hash[player_number])
	{
		vm->live_calls++;
		vm->last_live = player_number;
	}
	modify_pc(ps, 1);
}
