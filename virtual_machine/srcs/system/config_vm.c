/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:33:43 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 15:24:06 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		config_vm(t_vm *vm, int argc, char **argv)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->argv = argv;
	vm->argc = argc;
	vm->cycle = 1;
	vm->tot_cycle = 1;
	vm->cycle_to_die = CYCLE_TO_DIE;
}
