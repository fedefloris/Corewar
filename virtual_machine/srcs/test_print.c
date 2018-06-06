/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:22:57 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/06 20:43:45 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Testprint

#include "virtual_machine.h"

void				test_print(t_vm *vm)
{
	while (vm->file)
	{
		printf("FILE: %s\n", vm->file->file_name);
		while (vm->file->byte_code)
		{
			printf("%c", vm->file->byte_code->byte);
			vm->file->byte_code = vm->file->byte_code->next;
		}
		vm->file = vm->file->next;
	}
}
