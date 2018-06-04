/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/04 23:27:13 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_vm			*create_virtual_machine(int argc, char **argv)
{
	t_vm			*vm;

	if(!(vm = (t_vm *)malloc(sizeof(t_vm))))
		exit(1);
	vm->argv = argv;
	vm->argc = argc;
	vm->file = NULL;
	return (vm);
}

int					main(int argc, char **argv)
{
	t_vm			*vm;

	if (argc < 2)
	{
		ft_putstr("No args - CREATE USAGE!!!!\n");//Create usage
		return (0);
	}
	vm = create_virtual_machine(argc, argv);
	virtual_machine(vm);
	//free fraeme here.
	return (0);
}
