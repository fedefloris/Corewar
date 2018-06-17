/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/11 11:21:03 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_vm			*create_vm(int argc, char **argv)
{
	t_vm			*vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		error_exit(vm, "Malloc failed, virtual machine creation");
	ft_bzero(vm, sizeof(t_vm));
	vm->argv = argv;
	vm->argc = argc;
	vm->dump = -1;
	vm->cycle = 1;
	vm->tot_cycle = 1;
	vm->cycle_to_die = CYCLE_TO_DIE;
	return (vm);
}

int					main(int argc, char **argv)
{
	t_vm			*vm;

	if (argc < 2)
	{
		ft_putstr("Provide 1 or more arguments\n");
		display_usage();
		exit(1);
	}
	vm = create_vm(argc, argv);
	parse_handler(vm);
	exec_vm(vm);
	test_print(vm); //Remove
	free_vm(vm);
	return (0);
}
