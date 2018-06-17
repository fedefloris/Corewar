/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/17 04:06:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_aff(t_vm *vm, t_process *ps)
{
	int				reg;
	int				pc;

	get_address(ps, 2, &pc);
	reg = vm->memory[pc];
	printf("Inside op_aff\n");
	if (vm->aff)
	{
		ft_printf(CYAN);
		ft_printf("Aff r%-2d [", reg);
		ft_printf("%c", ps->r[reg] % 256);
		ft_printf("]\n");
		ft_printf(RESET);
	}
	modify_pc(ps, 3);
}
