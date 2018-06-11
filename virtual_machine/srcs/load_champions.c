/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:18:39 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/11 11:18:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static size_t		get_gap_between_champs(t_vm *vm)
{
	size_t		total_champs_size;
	size_t		count_of_champs;
	t_champ		*champ;

	champ = vm->champ;
	count_of_champs = 0;
	total_champs_size = 0;
	while (champ)
	{
		count_of_champs++;
		total_champs_size += champ->program_size;
		champ = champ->next;
	}
	return ((MEM_SIZE - total_champs_size) / count_of_champs);
}

static void			copy_program(t_vm *vm, size_t pos, t_champ *champ)
{
	size_t		i;

	i = 0;
	while (i < champ->program_size)
	{
	// 	vm[pos + i] = champ[i];
		i++;
	}
}

void				load_champions(t_vm *vm)
{
	t_champ		*champ;
	size_t		gap;
	size_t		pos;

	pos = 0;
	champ = vm->champ;
	gap = get_gap_between_champs(vm);
	while (champ)
	{
		copy_program(vm, pos, champ);
		pos += champ->program_size + gap;
		champ = champ->next;
	}
}
