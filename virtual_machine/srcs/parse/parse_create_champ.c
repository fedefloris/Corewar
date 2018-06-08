/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/08 16:57:41 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_champ		*create_champ(t_vm *vm)
{
	t_champ			*champ;

	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		error_exit(vm);
	ft_bzero(champ, sizeof(*champ));
	int i = 0;

	while (i <= REG_NUMBER)
		printf("Val %ju\n", champ->r[i++]);
	return (champ);
}

void				get_champion_number(t_vm *vm)
{
	t_champ			*champ;

	champ = vm->champ;
	if (!champ)
		error_exit(vm);//no champ
	champ->number = 1;
	while (champ->next)
	{
		champ->next->number = champ->number + 1;
		champ = champ->next;
	}
}

void				parse_create_champ(t_vm *vm)
{
	t_champ			*champ;

	while (--vm->argc)
	{
		champ = create_champ(vm);
		champ->file_name = vm->argv[vm->argc];
		if (!vm->champ)
			vm->champ = champ;
		else
		{
			champ->next = vm->champ;
			vm->champ = champ;
		}
	}
	get_champion_number(vm);
}
