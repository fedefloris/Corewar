/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:26:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/12 19:19:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			modify_negative(t_process *process, int modify)
{
	int				pc;

	pc = process->pc;
	while (modify++)
	{
		if (pc == 0)
			pc = MEM_SIZE - 1;
		else
			pc--;
	}
	process->pc = pc;
}

static void			modify_positive(t_process *process, int modify)
{
	int				pc;

	pc = process->pc;
	while (modify--)
	{
		if (pc == MEM_SIZE - 1)
			pc = 0;
		else
			pc++;
	}
	process->pc = pc;
}

void				modify_pc(t_process *process, int modify)
{
	if (modify > 0)
		modify_positive(process, modify);
	if (modify < 0)
		modify_negative(process, modify);
}
