/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_virtual_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:55:52 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/06 13:59:59 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				free_vm(t_vm *vm)
{
	free_names(vm->name);
	free_champs(vm->champ);
	free_processes(vm->process);
	free_ops_queue(vm->ops_queue);
}
