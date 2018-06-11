/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:25:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 15:33:16 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				get_bytes(t_vm *vm, t_champ *champ)
{
	int				i;
	int				bytes_len;
	t_byte_code		*byte_code;
	t_byte_code		*start;

	i = 0;
	bytes_len = 0;
	start = champ->byte_code;
	while (start && i++ < 137)
		start = start->next;
	byte_code = start;
	while (byte_code)
	{
		bytes_len++;
		byte_code = byte_code->next;
	}
	number_of_bytes = bytes_len;
	byte_code = start;
	if (!(champ->bytes = (char *)malloc(sizeof(char))))
		error_exit(vm, "Malloc failed (champ name)");
	i = 0;
	while (byte_code && bytes_len--)
	{
		champ->[i++] = byte_code->byte;
		byte_code = byte_code->next;
	}
}

void				get_name(t_vm *vm, t_champ *champ)
{
	int				i;
	int				name_len;
	t_byte_code		*byte_code;
	t_byte_code		*start;

	i = 0;
	name_len = 0;
	start = champ->byte_code;
	while (start && i++ < 4)
		start = start->next;
	byte_code = start;
	while (byte_code && byte_code->byte)
	{
		name_len++;
		byte_code = byte_code->next;
	}

	byte_code = start;
	if (!(champ->bytes = (char *)malloc(sizeof(char))))
		error_exit(vm, "Malloc failed (champ bytes)");
	i = 0;
	while (byte_code && name_len--)
	{
		champ->bytes[i++] = byte_code->byte;
		byte_code = byte_code->next;
	}
}

void				parse_bytes(t_vm *vm)
{
	t_champ			*champ;

	champ = vm->champ;
	while (champ)
	{
		get_name(vm, champ);
		champ = champ->next;
		get_bytes(vm, champ):
	}
}
