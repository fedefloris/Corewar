/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:44:02 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 17:44:03 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		exec_process(t_vm *vm, t_process *ps)
{
	ps->op = NULL;
	ps->pc_tmp = ps->pc;
	save_op(ps, (int)vm->memory[ps->pc]);
}
