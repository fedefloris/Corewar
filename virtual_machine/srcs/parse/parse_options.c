/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:05:21 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/10 21:26:26 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			parse_n(t_vm *vm)
{
	int				i;
	int				tmp;
	char			**argv;

	i = 1;
	argv = vm->argv;

	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (argv[i + 1] && (argv[i + 2] && (ft_strcmp(argv[i + 2], "-dump") && ft_strcmp(argv[i + 2], "-n"))))
				tmp = ft_atoi(argv[i + 1]);
			else
				error_exit(vm, "Incorrect format. [[-n number] champion1.cor]");
			if (tmp < 1)
				error_exit(vm, "Declare player number greater than 0");
			if (tmp)
				printf("N is %d\n", tmp);
				//create_name(vm, tmp, i);
		}
		i++;
		tmp = 0;
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
