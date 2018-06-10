/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:52:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/10 16:52:56 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				exec_vm(t_vm *vm)
{
	while (1)
	{
		// execute every process
		vm->cycle++;
		if (vm->cycle % CYCLE_TO_DIE == 0)
		{
			// if one process didn't call live delete it
		}
		// if ()
	}
}
