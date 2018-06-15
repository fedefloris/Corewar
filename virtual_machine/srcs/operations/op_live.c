/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/15 00:31:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_live(t_vm *vm, t_process *ps)
{
	int				player_number;

	ft_printf("Inside op_live\n");
	get_next_bytes(vm, ps, &player_number, 4);
	if (vm->live_hash[player_number])
	{
		vm->live_calls++;
		ps->live_calls++;
		vm->last_live = player_number;
	}
	iterate_pc(ps);
}
