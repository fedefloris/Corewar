/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:03:26 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 22:06:32 by dhojt            ###   ########.fr       */
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
		vm->last_live = player_number;
	}
	modify_pc(ps, 1);
	// ft_printf("A process shows that player %s (%s) is alive",
	// 				player_number, vm->live_hash[player_number]);
}
