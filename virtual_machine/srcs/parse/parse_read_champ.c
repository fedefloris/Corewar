/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_champ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:42:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 12:06:15 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static t_byte_code	*create_byte_code(t_vm *vm)
{
	t_byte_code		*byte_code;

	if (!(byte_code = (t_byte_code*)malloc(sizeof(t_byte_code))))
		error_exit(vm, "Malloc failed, Byte Code creation.");
	ft_bzero(byte_code, sizeof(t_byte_code));
	return (byte_code);
}

static void			fill(t_vm *vm, t_champ *champ, char *buf, int read_val)
{
	t_byte_code		*byte_code;
	t_byte_code		*seek;

	seek = champ->byte_code;
	while (seek && seek->next)
		seek = seek->next;
	while (read_val--)
	{
		byte_code = create_byte_code(vm);
		byte_code->byte = *buf;
		if (!seek)
		{
			champ->byte_code = byte_code;
			seek = byte_code;
		}
		else
		{
			seek->next = byte_code;
			seek = seek->next;
		}
		buf++;
	}
}

static void			do_read_champ(t_vm *vm, t_champ *champ)
{
	int				fd;
	int				read_val;
	char			buf[SIZE_OF_BUFF];

	if ((fd = open(champ->file_name, O_RDONLY)) < 0)
		error_exit(vm, "Failed to open file");
	while (1)
	{
		ft_bzero(buf, SIZE_OF_BUFF);
		read_val = read(fd, buf, SIZE_OF_BUFF);
		if (read_val < 0)
			error_exit(vm, "Failed to open file");
		if (!read_val)
			break ;
		fill(vm, champ, buf, read_val);
	}
}

void				parse_read_champ(t_vm *vm)
{
	t_champ			*champ;

	champ = vm->champ;
	while (champ)
	{
		if (!ft_strstr(champ->file_name, ".cor"))
			error_exit(vm, "Files must be .cor");
		do_read_champ(vm, champ);
		champ = champ->next;
	}
}
