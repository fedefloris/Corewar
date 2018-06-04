/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/04 21:34:16 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_vm			*create_virtual_machine(char **argv)
{
	t_vm			*vm;

	if(!(vm = (t_vm *)malloc(sizeof(t_vm))))
		exit(1);
	vm->parser = NULL;
	vm->argv = argv;
	return (vm);
}

int					main(int argc, char **argv)
{
	t_vm			*vm;

	if (argc < 2)
		ft_putstr("No args - CREATE\n");//Create usage
	vm = create_virtual_machine(argv);
	virtual_machine(vm);
	//free fraeme here.
	return (0);
}
