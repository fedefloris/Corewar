/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:29:02 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/21 15:35:04 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void			parse_dump(t_vm *vm, char **argv, int i)
{
	if (!ft_strcmp(argv[i], "-dump"))
	{
		if (vm->dump)
			error_exit(vm, "Declare -dump once only");
		if (argv[i + 1])
			vm->dump = ft_atoi(argv[i + 1]);
		else
			error_exit(vm, "No nbr_cycles ./corewar [-dump nbr_cycles]");
		if (vm->dump < 1)
			error_exit(vm, "Declare nbr_cycles greater than 0");
	}
}
