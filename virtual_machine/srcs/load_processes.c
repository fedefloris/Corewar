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

static size_t		get_gap_between_champs(t_vm *vm)
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

static void			copy_program(t_vm *vm, size_t pos, t_champ *champ)
{
	size_t		i;

	i = 0;
	while (i < champ->prog_size)
	{
		vm->memory[pos + i] = champ->bytes[i];
		i++;
	}
}

static void			add_process(t_vm *vm, t_champ *champ, size_t pc)
{
	t_process	*process;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		error_exit(vm, "Malloc failed, process creation.");
	process->number = champ->number;
	ft_bzero(process->r, REG_NUMBER + 1);
	process->r[1] = process->number;
	process->pc = pc;
	process->carry = 0;
	process->next = NULL;
	process->next = vm->process;
	vm->process = process;
}

void				load_processes(t_vm *vm)
{
	t_champ		*champ;
	size_t		gap;
	size_t		pos;

	pos = 0;
	champ = vm->champ;
	gap = get_gap_between_champs(vm);
	while (champ)
	{
		add_process(vm, champ, pos);
		copy_program(vm, pos, champ);
		pos += gap;
		champ = champ->next;
	}
}
