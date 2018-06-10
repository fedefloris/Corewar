/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 00:28:27 by dhojt            ###   ########.fr       */
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
	t_name			*name;
	int				number;
	int				flag;

	champ = vm->champ;
	number = 1;
	if (!champ)
		error_exit(vm, "No Champ");
	while (champ)
	{
		flag = 0;
		while (!flag)
		{
			name = vm->name;
			flag = 1;
			while (name)
			{
				if (number == name->num)
					flag = 0;
				name = name->next;
			}
			if (!flag)
				number++;
		}
		if (!champ->number)
		{
			champ->number = number;
			number++;
		}
		champ = champ->next;
	}
}

void				parse_create_champ(t_vm *vm)
{
	t_champ			*champ;
	t_name			*name;

	while (--vm->argc)
	{
		name = vm->name;
		if (vm->argc > 1 && (!ft_strcmp(vm->argv[vm->argc - 1], "-dump") ||
					!ft_strcmp(vm->argv[vm->argc - 1], "-n")))
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
				while (name)
				{
					if (vm->argc == name->pos)
						champ->number = name->num;
					name = name->next;
				}
			}
		}
	}
	get_champion_number(vm);
}
