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

static void		insertion_sort(t_vm *vm, t_ps_op *op)
{
	// t_ps_op		*ops;

	// ops = vm->ops_queue;
	// while (ops && ops->ps->number > op->ps->number)
	op->next = vm->ops_queue;
	vm->ops_queue = op;
}

void			add_op_to_queue(t_vm *vm, t_process *ps)
{
	t_ps_op		*op;

	if (!ps->op)
		return ;
	if (!(op = (t_ps_op*)malloc(sizeof(t_ps_op))))
		error_exit(vm, "Malloc failed, op creation.");
	op->ps = ps;
	op->op = ps->op;
	op->next = NULL;
	insertion_sort(vm, op);
}
