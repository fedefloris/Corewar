/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 21:05:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/21 22:34:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			match_pc(t_vm *vm, int i, int *ps_id)
{
	t_process		*ps;

	ps = vm->process;
	while (ps)
	{
		if (i == ps->pc)
		{	
			*ps_id = ps->id;
			break ;
		}
		ps = ps->next;
	}
}

static void			print_line(t_vm *vm, char *bytes, int pane, int byte_width)
{
	int				j;
	int				k;
	int				ps_id;

	j = 0;
	ft_printf("%.8x  ", pane);
	while (j < byte_width)
	{
		k = 0;
		while (k++ < 8)
		{
			ft_printf(BLUE);
			ps_id = 0;
			if (pane >= MEM_SIZE)
				return ;
			match_pc(vm, pane, &ps_id);
			if (ps_id)
			{
				(ps_id == 1) ? ft_printf(B_RED) : 0;
				(ps_id == 2) ? ft_printf(B_GREEN) : 0;
				(ps_id == 3) ? ft_printf(B_CYAN) : 0;
				(ps_id == 4) ? ft_printf(B_YELLOW) : 0;
			}
			ft_printf("%.2x ", (unsigned char)bytes[pane++]);
			ft_printf(RESET);
		}
		ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

static void			print_cycle_info(t_vm *vm)
{
	t_process		*ps;
	int				player_num;

	player_num = 0;
	ft_printf("CYCLE NUMBER[%6d]   ", vm->tot_cycle);
	ft_printf("CYCLE[%6d]   ", vm->cycle);
	ft_printf("CYCLE_TO_DIE[%6d]   ", vm->cycle_to_die);
	ft_printf("CHECKS[%6d]\n\n", vm->checkups);
	while (player_num++ < MAX_PLAYERS)
	{
		ps = vm->process;
		while (ps)
		{
			if (ps->id == player_num)
			{
				ft_printf("Player %d (%s)\n", ps->number, ps->name);
					break ;
			}
			ps = ps->next;
		}
	}
}

void				dump_memory(t_vm *vm, int byte_width, int exit_flag)
{
	char			*bytes;
	int				pane;

	bytes = vm->memory;
	pane = 0;
	while (pane < MEM_SIZE)
	{
		print_line(vm, bytes, pane, byte_width);
		pane += (byte_width * 8);
	}
	if (exit_flag)
	{
		free_vm(vm);
		exit(0);
	}
	print_cycle_info(vm);

}
