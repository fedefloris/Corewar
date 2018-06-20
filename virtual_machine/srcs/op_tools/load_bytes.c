/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:21:06 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/20 12:21:10 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		load_bytes(t_vm *vm, t_process *ps, int reg, int start)
{
	int		value;
	int		i;

	i = 0;
	value = 0;
	while (i < REG_SIZE)
	{
		value <<= 8;
		value |= vm->memory[(start + i) % MEM_SIZE];
		i++;
	}
	ps->r[get_r(reg)] = value;
}
