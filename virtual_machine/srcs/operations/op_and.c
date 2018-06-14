/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 18:29:00 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				op_and(t_vm *vm, t_process *ps)
{
	int				r1;
	int				r2;
	int				r3;

	printf("Inside op_and\n");//
	get_next_bytes(vm, ps, &r1, 1);
	get_next_bytes(vm, ps, &r2, 1);
	get_next_bytes(vm, ps, &r3, 1);
	ps->r[r3] = ps->r[r1] + ps->r[r2];
	modify_pc(ps, 1);
	if (!r3)
		ps->carry = 1;
	ps->carry = 1;
	modify_pc(ps, 8);
}
