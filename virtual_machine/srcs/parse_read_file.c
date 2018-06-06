/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:42:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/06 20:39:54 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"
#include <fcntl.h>
#include <unistd.h>

static t_byte_code	*create_byte_code(t_vm *vm)
{
	t_byte_code		*byte_code;

	if (!(byte_code = (t_byte_code *)malloc(sizeof(t_byte_code))))
		error_exit(vm);
	ft_bzero(byte_code, sizeof(*byte_code));
	return (byte_code);
}

static void			fill_bytes(t_vm *vm, t_file *file, char *buf, int read_val)
{
	t_byte_code		*byte_code;
	t_byte_code		*seek;

	seek = file->byte_code;
	while (seek && seek->next)
		seek = seek->next;
	while (read_val--)
	{
		byte_code = create_byte_code(vm);
		byte_code->byte = *buf;
		if (!seek)
		{
			file->byte_code = byte_code;
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

static void			do_read_file(t_vm *vm, t_file *file)
{
	int				fd;
	int				read_val;
	char			buf[SIZE_OF_BUFF];

	if ((fd = open(file->file_name, O_RDONLY)) < 0)
		error_exit(vm);//Failed_to_open.
	while (1)
	{
		ft_bzero(buf, SIZE_OF_BUFF);
		read_val = read(fd, buf, SIZE_OF_BUFF);
		if (read_val < 0)
			error_exit(vm);//Failed to read.
		if (!read_val)
			break ;
		fill_bytes(vm, file, buf, read_val);
	}
}

void				parse_read_file(t_vm *vm)
{
	t_file			*file;

	file = vm->file;
	while (file)
	{
		do_read_file(vm, file);
		file = file->next;
	}
}
