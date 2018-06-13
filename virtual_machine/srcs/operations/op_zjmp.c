/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:04:41 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 16:49:30 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_zjmp(t_vm *vm, t_process *ps)
{
	int				modify;

	if (ps->carry)
	{
		modify_pc(ps, 1);
		modify = vm->memory[ps->pc];
		modify <<= 8;
		modify_pc(ps, 1);
		modify += vm->memory[ps->pc];
		modify_pc(ps, modify);
	}
	modify_pc(ps, 1);
}
