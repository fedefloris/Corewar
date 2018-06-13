/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:04:41 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 22:05:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_zjmp(t_vm *vm, t_process *ps)
{
	int				modify;

	if (ps->carry)
	{
		get_next_bytes(vm, ps, &modify, 2);
		modify_pc(ps, modify % IDX_MOD);
	}
	else
		modify_pc(ps, 3);
}
