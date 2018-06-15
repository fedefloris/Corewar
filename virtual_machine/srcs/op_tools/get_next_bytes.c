/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:19:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 23:59:36 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

/*
** n bytes from position pc + 1 will be stored in value
*/

void				get_next_bytes(t_vm *vm, t_process *ps, int *value, int n)
{
	*value = 0;
	while (n--)
	{
		modify_pc_tmp(ps, 1);
		*value <<= 8;
		*value |= vm->memory[ps->pc_tmp];
	}
}
