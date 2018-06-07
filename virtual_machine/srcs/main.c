/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 18:36:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_vm			*create_virtual_machine(int argc, char **argv)
{
	t_vm			*vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		exit(1);
	ft_bzero(vm, sizeof(*vm));
	vm->argv = argv;
	vm->argc = argc;
	return (vm);
}

int					main(int argc, char **argv)
{
	t_vm			*vm;

	if (argc < 2 || argc > MAX_ARGS_NUMBER)
		usage(vm, 1);
	vm = create_virtual_machine(argc, argv);
	virtual_machine(vm);
	test_print(vm);//Remove
	free_virtual_machine(vm);
	return (0);
}
