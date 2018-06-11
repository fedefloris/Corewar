/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count_champions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:26:27 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 21:31:17 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				parse_count_champions(t_vm *vm)
{
	int				i;
	t_champ			*champ;

	i = 0;
	champ = vm->champ;
	while (champ)
	{
		i++;
		champ = champ->next;
	}
	if (i > MAX_PLAYERS)
		error_exit(vm, "Too many Champions");
}
