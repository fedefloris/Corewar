/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op_to_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:03:37 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 18:03:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		add_op_to_queue(t_vm *vm, t_process *ps)
{
	if (!ps->op)
		return ;
	ft_printf("Exec_ps %d | pc  %d | carry %d | op_code %d\n",
			ps->number, ps->pc, ps->carry, (int)vm->memory[ps->pc]);
	ps->op(vm, ps);
}
