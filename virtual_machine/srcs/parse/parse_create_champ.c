/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/10 23:01:07 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_champ		*create_champ(t_vm *vm)
{
	t_champ			*champ;

	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		error_exit(vm, "Malloc failed (Create Champ)");
	ft_bzero(champ, sizeof(*champ));
	int i = 0;
	return (champ);
}

void				get_champion_number(t_vm *vm)
{
	t_champ			*champ;

	champ = vm->champ;
	if (!champ)
		error_exit(vm, "No Champ");
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
		if (vm->argc > 1 && !ft_strcmp(vm->argv[vm->argc - 1], "-dump"))
			vm->argc -= 1;
		else
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
	}
	get_champion_number(vm);
}
