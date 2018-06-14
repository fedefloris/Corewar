/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_pc_tmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 23:49:41 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/15 00:09:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				modify_pc_tmp(t_process *ps, int modify)
{
	ps->pc_tmp += modify;
	if (ps->pc_tmp > 0)
		ps->pc_tmp %= MEM_SIZE;
	else if (ps->pc_tmp < 0)
		ps->pc_tmp = (ps->pc_tmp % MEM_SIZE) + MEM_SIZE;
}
