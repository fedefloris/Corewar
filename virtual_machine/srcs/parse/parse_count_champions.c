/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count_champions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:26:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 19:31:46 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			create_live_hash(t_vm *vm, int largest_num)
{
	t_champ			*champ;

	champ = vm->champ;
	if (!(vm->live_hash = (int *)malloc(sizeof(int) * (largest_num + 1))))
		error_exit(vm, "Malloc failed (name hash)");
	ft_bzero(vm->live_hash, largest_num + 1);
	while (champ)
	{
		vm->live_hash[champ->number] = 1;
		champ = champ->next;
	}
}

void				parse_count_champions(t_vm *vm)
{
	int				i;
	int				largest_num;
	t_champ			*champ;

	i = 0;
	largest_num = 0;
	champ = vm->champ;
	while (champ)
	{
		i++;
		if (champ->number > largest_num)
			largest_num = champ->number;
		champ = champ->next;
	}
	if (i > MAX_PLAYERS)
		error_exit(vm, "Too many Champions");
	create_live_hash(vm, largest_num);
}
