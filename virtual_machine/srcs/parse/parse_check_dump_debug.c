/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_dump_debug.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:36:37 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/21 16:36:44 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				parse_check_dump_debug(t_vm *vm)
{
	if (vm->dump && vm->debug)
		error_exit(vm, "You must only use one of either dump or debug");
}
