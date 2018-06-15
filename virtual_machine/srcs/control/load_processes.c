/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:18:39 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/11 21:17:18 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static size_t	get_gap_between_champs(t_vm *vm)
{
	size_t		count_of_champs;
	t_champ		*champ;

	champ = vm->champ;
	count_of_champs = 0;
	while (champ)
	{
		count_of_champs++;
		champ = champ->next;
	}
	return (MEM_SIZE / count_of_champs);
}

static void		move_last_process_to_top(t_vm *vm)
{
	t_process	*last;
	t_process	*prev;

	last = vm->process;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
	{
		prev->next = NULL;
		last->next = vm->process;
		vm->process = last;
	}
}

void			load_processes(t_vm *vm)
{
	t_champ		*champ;
	size_t		gap;
	size_t		pos;

	pos = 0;
	champ = vm->champ;
	gap = get_gap_between_champs(vm);
	while (champ)
	{
		load_process(vm, champ, pos);
		pos += gap;
		champ = champ->next;
	}
	move_last_process_to_top(vm);
}
