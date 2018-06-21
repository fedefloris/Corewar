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

int			main(int argc, char **argv)
{
	t_vm			vm;

	if (argc < 2)
	{
		ft_putstr("Provide 1 or more arguments\n");
		display_usage();
		exit(1);
	}
	config_vm(&vm, argc, argv);
	parse_handler(&vm);
	exec_vm(&vm);
	free_vm(&vm);
	return (0);
}
