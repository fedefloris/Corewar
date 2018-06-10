/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:05:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 01:10:23 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			create_name(t_vm *vm, int num, int pos)
{
	t_name			*name;

	if (!(name = (t_name *)malloc(sizeof(t_name))))
		error_exit(vm, "Malloc failed, num creation");
	bzero(name, sizeof(*name));
	name->num = num;
	name->pos = pos;
	if (!vm->name)
		vm->name = name;
	else
	{
		name->next = vm->name;
		vm->name = name;
	}
}

static void			parse_n(t_vm *vm)
{
	int				i;
	int				num;
	char			**argv;

	i = 1;
	argv = vm->argv;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (argv[i + 1] && (argv[i + 2] &&
						(ft_strcmp(argv[i + 2], "-dump") &&
						ft_strcmp(argv[i + 2], "-n"))))
				num = ft_atoi(argv[i + 1]);
			else
				error_exit(vm, "Incorrect format. [[-n number] champion1.cor]");
			if (num < 1)
				error_exit(vm, "Declare player number greater than 0");
			if (num)
				create_name(vm, num, i + 2);
		}
		i++;
		num = 0;
	}
}

static void			parse_dump(t_vm *vm)
{
	int				i;
	char			**argv;

	i = 1;
	argv = vm->argv;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-dump"))
		{
			if (vm->dump != -1)
				error_exit(vm, "Declare -dump once only. See usage with -u");
			if (argv[i + 1])
				vm->dump = ft_atoi(argv[i + 1]);
			else
				error_exit(vm, "No nbr_cycles ./corewar [-dump nbr_cycles]");
			if (vm->dump < 1)
				error_exit(vm, "Declare nbr_cycles greater than 0");
		}
		i++;
	}
	printf("-dump %d\n", vm->dump);
}

void				parse_options(t_vm *vm)
{
	parse_dump(vm);
	parse_n(vm);
}
