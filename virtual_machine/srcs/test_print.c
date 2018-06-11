/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:22:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/10 18:29:23 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Testprint

#include "virtual_machine.h"

void				test_print(t_vm *vm)
{
	do_op(vm, 16);
	while (vm->champ)
	{
		printf("NUMBER:     %d\n", vm->champ->number);
		printf("CHAMP R[1]: %ju\n", vm->champ->r[1]);
		while (vm->champ->byte_code)
		{
			printf("%c", vm->champ->byte_code->byte);
			vm->champ->byte_code = vm->champ->byte_code->next;
		}
		vm->champ = vm->champ->next;
	}
}
