/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:22:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 21:18:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Testprint

#include "virtual_machine.h"

void				test_print(t_vm *vm)
{
	// while (vm->champ)
	// {
		//printf("NUMBER:     %d\n", vm->champ->number);
		//printf("NAME  :     %s\n", vm->champ->name);
		//printf("NUMBY :     %d\n", vm->champ->program_size);
	// 	while (vm->champ->prog_size--)
	// 	{
	// 		printf("%c", *vm->champ->bytes);
	// 		vm->champ->bytes++;
	// 	}
	// 	vm->champ = vm->champ->next;
	// }
	// while (vm->process)
	// {
		// ft_printf();
		// vm->process = vm->process->next;
	// }
	ft_putnstr(vm->memory, MEM_SIZE);
}
