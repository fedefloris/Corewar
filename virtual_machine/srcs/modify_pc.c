/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:26:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/12 19:09:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "virtual_machine.h"
//
//
//
#include <stdlib.h>
#include <stdio.h>
#define REG_NUMBER 15
#define MEM_SIZE (4*1024)
typedef struct			s_process
{
	int					number;
	intmax_t			r[REG_NUMBER + 1];
	int					pc;
	char				carry;
	struct s_process	*next;
}						t_process;

static void			modify_negative(t_process *process, int modify)
{
	int				pc;

	pc = process->pc;
	while(modify++)
	{
		if (pc == 0)
			pc = MEM_SIZE -1;
		else
			pc--;
	}
	process->pc = pc;
}

static void			modify_positive(t_process *process, int modify)
{
	int				pc;

	pc = process->pc;
	while(modify--)
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

//
int					main(void)
{
	t_process				*process;
	process = (t_process *)malloc(sizeof(t_process));
	process->pc = 1267;
	modify_pc(process, -60);
	printf("%d\n", process->pc);
	return (0);
}
