/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:01:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 18:01:57 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		exec_ops_queue(t_vm *vm)
{
	t_ps_op		*prev;

	while (vm->ops_queue)
	{
		prev = vm->ops_queue;
		vm->ops_queue = vm->ops_queue->next;
		ft_printf("Exec_ps %d | pc  %d | carry %d | op_code %d | sleep_cycles %d\n",
			prev->ps->number, prev->ps->pc,
			prev->ps->carry, (int)vm->memory[prev->ps->pc],
			prev->ps->sleep_cycles);
		prev->op(vm, prev->ps);
		prev->ps->op = NULL;
		free(prev);
	}
}
