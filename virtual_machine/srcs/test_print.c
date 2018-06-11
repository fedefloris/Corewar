/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:22:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 01:10:58 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Testprint

#include "virtual_machine.h"

void				test_print(t_vm *vm)
{
	while (vm->champ)
	{
		printf("NUMBER:     %d\n", vm->champ->number);
		while (vm->champ->byte_code)
		{
			printf("%c", vm->champ->byte_code->byte);
			vm->champ->byte_code = vm->champ->byte_code->next;
		}
		vm->champ = vm->champ->next;
	}
}
