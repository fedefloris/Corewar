/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/06 20:44:32 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_file		*create_file(t_vm *vm)
{
	t_file			*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		error_exit(vm);
	ft_memset(file, 0, sizeof(*file));
	return (file);
}

void				parse_create_file(t_vm *vm)
{
	t_file			*file;

	while (--vm->argc)
	{
		file = create_file(vm);
		file->file_name = vm->argv[vm->argc];
		if (!vm->file)
			vm->file = file;
		else
		{
			file->next = vm->file;
			vm->file = file;
		}
	}
}
