/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/17 19:27:51 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_champ		*create_champ(t_vm *vm)
{
	t_champ			*champ;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		error_exit(vm, "Malloc failed (Create Champ)");
	ft_bzero(champ, sizeof(*champ));
	champ->file_name = vm->argv[vm->argc];
	champ->next = vm->champ;
	vm->champ = champ;
	return (champ);
}

static void			check_duplicate_names(t_vm *vm)
{
	t_champ			*seek;
	t_champ			*compare;

	compare = vm->champ;
	while (compare->next)
	{
		seek = compare->next;
		while (seek)
		{
			if (compare->number == seek->number)
				error_exit(vm, "Duplicate names");
			seek = seek->next;
		}
		compare = compare->next;
	}
}

static void			get_champion_number(t_vm *vm)
{
	t_champ			*champ;
	t_name			*name;
	int				number;
	int				flag;

	champ = vm->champ;
	number = 1;
	(!champ) ? error_exit(vm, "No Champ") : 0;
	while (champ && !(flag = 0))
	{
		while (!flag && (name = vm->name))
		{
			flag = 1;
			while (name)
			{
				(number == name->num) ? flag = 0 : 0;
				name = name->next;
			}
			if (!flag)
				number++;
		}
		(!champ->number) ? champ->number = number++ : 0;
		champ = champ->next;
	}
	check_duplicate_names(vm);
}

void				parse_create_champ(t_vm *vm)
{
	t_champ			*champ;
	t_name			*name;
	char			*argv;

	while (--vm->argc && (argv = vm->argv[vm->argc]))
	{
		name = vm->name;
		if (vm->argc > 1 && (!ft_strcmp(vm->argv[vm->argc - 1], "-dump") ||
					!ft_strcmp(vm->argv[vm->argc - 1], "-n")))
			vm->argc -= 1;
		else if (!ft_strcmp(argv, "-a") || !ft_strcmp(argv, "-x") ||
				!ft_strcmp(argv, "-d") || !ft_strcmp(argv, "-X"))
			;
		else
		{
			champ = create_champ(vm);
			while (name)
			{
				(vm->argc == name->pos) ? champ->number = name->num : 0;
				name = name->next;
			}
		}
	}
	get_champion_number(vm);
}
