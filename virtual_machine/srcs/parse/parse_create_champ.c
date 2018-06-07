/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:00:00 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/07 19:10:14 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_champ		*create_champ(t_vm *vm)
{
	t_champ			*champ;

	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		error_exit(vm);
	ft_bzero(champ, sizeof(*champ));
	return (champ);
}

void				parse_create_champ(t_vm *vm)
{
	t_champ			*champ;

	while (--vm->argc)
	{
		champ = create_champ(vm);
		champ->file_name = vm->argv[vm->argc];
		if (!vm->champ)
			vm->champ = champ;
		else
		{
			champ->next = vm->champ;
			vm->champ = champ;
		}
	}
}
