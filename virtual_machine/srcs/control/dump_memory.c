/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 21:05:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/20 15:29:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			match_pc(t_vm *vm, int i)
{
	t_process		*ps;

	ps = vm->process;
	while (ps)
	{
		if (i == ps->pc)
			ft_printf(RED);
		ps = ps->next;
	}
}

static void			print_line(t_vm *vm, char *bytes, int pane, int byte_width)
{
	int				j;
	int				k;

	j = 0;
	ft_printf("%.8x  ", pane);
	while (j < byte_width)
	{
		k = 0;
		while (k++ < 8)
		{
			if (pane >= MEM_SIZE)
				return ;
			match_pc(vm, pane);
			ft_printf("%.2x %s", (unsigned char)bytes[pane++], RESET);
		}
		ft_printf(" ");
		j++;
	}
	ft_printf("\n");
}

void				dump_memory(t_vm *vm, int byte_width)
{
	char			*bytes;
	int				pane;
	int				i;

	bytes = vm->memory;
	pane = 0;
	while (pane < MEM_SIZE)
	{
		print_line(vm, bytes, pane, byte_width);
		pane += (byte_width * 8);
	}
	free_vm(vm);
	exit(0);
}
