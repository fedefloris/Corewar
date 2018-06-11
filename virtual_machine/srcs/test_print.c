/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:22:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 17:10:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Testprint

#include "virtual_machine.h"

void				test_print(t_vm *vm)
{
	while (vm->champ)
	{
		//printf("NUMBER:     %d\n", vm->champ->number);
		//printf("NAME  :     %s\n", vm->champ->name);
		//printf("NUMBY :     %d\n", vm->champ->number_of_bytes);
		while (vm->champ->number_of_bytes--)
		{
			printf("%c", *vm->champ->bytes);
			vm->champ->bytes++;
		}
		vm->champ = vm->champ->next;
	}
}
