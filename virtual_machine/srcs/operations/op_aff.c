/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/17 19:01:11 by dhojt            ###   ########.fr       */
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
	if (vm->aff || vm->affd || vm->affx || vm->affX)
	{
		ft_printf(CYAN);
		ft_printf("Aff r%-2d [", reg);
		if (vm->aff)
			ft_printf("%C", ps->r[reg] % 256);
		else if (vm->affd)
			ft_printf("%d", ps->r[reg]);
		else if (vm->affx)
			ft_printf("%x", ps->r[reg]);
		else if (vm->affX)
			ft_printf("%X", ps->r[reg]);
		ft_printf("]\n");
		ft_printf(RESET);
	}
	modify_pc(ps, 3);
}
