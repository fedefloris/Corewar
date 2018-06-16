/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/16 21:55:45 by dhojt            ###   ########.fr       */
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
		ft_printf("%sAff r%-2d [%c]%s\n", CYAN,  reg, ps->r[reg] % 256, RESET);
	modify_pc(ps, 3);
}
