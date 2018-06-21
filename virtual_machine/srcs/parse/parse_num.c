/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:34:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/21 17:00:43 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			create_num(t_vm *vm, int num, int pos)
{
	t_name			*name;

	if (!(name = (t_name *)malloc(sizeof(t_name))))
		error_exit(vm, "Malloc failed, num creation");
	name->num = num;
	name->pos = pos;
	name->next = vm->name;
	vm->name = name;
}

void				parse_num(t_vm *vm, char **argv, int i)
{
	int				num;

	if (!ft_strcmp(argv[i], "-n"))
	{
		if (argv[i + 1] && (argv[i + 2] &&
					(ft_strcmp(argv[i + 2], "-dump") &&
					ft_strcmp(argv[i + 2], "-n"))))
		{
			num = ft_atoi(argv[i + 1]);
			if (num < 1)
				error_exit(vm, "Declare player number greater than 0");
			if (num)
				create_num(vm, num, i + 2);
		}
		else
			error_exit(vm, "Incorrect format. [[-n number] champion1.cor]");
	}
}
