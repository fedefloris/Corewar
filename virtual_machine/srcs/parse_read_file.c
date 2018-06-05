/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:42:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/05 14:10:36 by dhojt            ###   ########.fr       */
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

	while (read_val--)
	{
		byte_code = create_byte_code(vm);
		byte_code->byte = buf[read_val];
		if (!file->byte_code)
			file->byte_code = byte_code;
		else
		{
			byte_code->next = file->byte_code;
			file->byte_code = byte_code;
		}
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
	while (vm->file)
	{
		while (vm->file->byte_code)
		{
			printf("%c", vm->file->byte_code->byte);
			vm->file->byte_code = vm->file->byte_code->next;
		}
		printf("\n\n");
		vm->file = vm->file->next;
	}
}
