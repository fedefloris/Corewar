/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:25:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 09:26:49 by dhojt            ###   ########.fr       */
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
	byte_code = champ->byte_code;
	while (byte_code && i++ < PROGRAM_NAME_LENGTH + COMMENT_LENGTH + 16)
		byte_code = byte_code->next;
	if (!(champ->bytes = (char *)malloc(sizeof(char) * champ->prog_size)))
		error_exit(vm, "Malloc failed (champ name)");
	i = 0;
	while (byte_code && i < champ->prog_size)
	{
		champ->bytes[i++] = byte_code->byte;
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
	if (!(champ->name = (char *)malloc(sizeof(char) * name_len)))
		error_exit(vm, "Malloc failed (champ name)");
	i = 0;
	while (byte_code && name_len--)
	{
		champ->name[i++] = byte_code->byte;
		byte_code = byte_code->next;
	}
}

void				get_prog_size(t_vm *vm, t_champ *champ)
{
	int				i;
	t_byte_code		*byte_code;

	i = 0;
	byte_code = champ->byte_code;
	while (byte_code && i++ < PROGRRAM_NAME_LENGTH + 8)
		byte_code = byte_code->next;
	i = 0;
	while (byte_code && i++ < 4)
	{
		champ->prog_size <<= 8;
		champ->prog_size += (unsigned char)byte_code->byte;
		byte_code = byte_code->next;
	}
	if (champ->prog_size > CHAMP_MAX_SIZE)
		error_exit(vm, "A champion is too big");
}

void				get_magic_number(t_vm *vm, t_champ *champ)
{
	int				i;
	t_byte_code		*byte_code;

	i = 0;
	byte_code = champ->byte_code;
	while (byte_code && i < 4)
	{
		if ((i == 0 && byte_code->byte == 0x0) ||
				(i == 1 && (unsigned char)byte_code->byte == 0xea) ||
				(i == 2 && (unsigned char)byte_code->byte == 0x83) ||
				(i == 3 && (unsigned char)byte_code->byte == 0xf3))
			;
		else
			error_exit(vm, "Bad magic number");
		byte_code = byte_code->next;
		i++;
	}
}

void				parse_bytes(t_vm *vm)
{
	t_champ			*champ;

	champ = vm->champ;
	while (champ)
	{
		get_prog_size(vm, champ);
		get_name(vm, champ);
		get_bytes(vm, champ);
		get_magic_number(vm, champ);
		champ = champ->next;
	}
}
