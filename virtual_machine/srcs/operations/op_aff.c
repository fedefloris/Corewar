/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:41:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_aff(t_vm *vm, t_process *ps)
{
	int				reg;
	int				pc;

	get_address(ps, 2, &pc);
	reg = vm->memory[pc];
	ft_printf("Inside op_aff\n");
	if (vm->aff || vm->affd || vm->affx || vm->affx2)
	{
		ft_printf(CYAN);
		ft_printf("Aff r%-2d [", reg);
		if (vm->aff)
			ft_printf("%C", ps->r[get_r(reg)] % 256);
		else if (vm->affd)
			ft_printf("%d", ps->r[get_r(reg)]);
		else if (vm->affx)
			ft_printf("%x", ps->r[get_r(reg)]);
		else if (vm->affx2)
			ft_printf("%X", ps->r[get_r(reg)]);
		ft_printf("]\n");
		ft_printf(RESET);
	}
	modify_pc(ps, 3);
}
