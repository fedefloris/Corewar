/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:19:36 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 21:55:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int					get_next_bytes(t_vm *vm, t_process *ps, int num)
{
	int				value;

	value = 0;
	while (num--)
	{
		modify_pc(ps, 1);
		value <<= 8;
		value += vm->memory[ps->pc];
	}
	return (value);
}
