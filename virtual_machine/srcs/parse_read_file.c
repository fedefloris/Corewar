/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:42:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/05 12:14:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"
#include <fcntl>
#include <unistd.h>

static void			do_read_file(t_file *file)
{
	int				fd;
	int				read_result;
	char			buf[SIZE_OF_BUFF];

	if ((fd = open(file->file_name, O_RDONLY)) < 0)
		error_exit(vm);//Failed_to_open.
	while (1)
	{
		read_result = read(fd, buf, SIZE_OF_BUFF);
		if (read_result < 0)
			error_exit(vm);//Failed to read.
		ft_strjoin(file->byte_code, buf);
		i
		


void				parse_read_file(t_vm *vm)
{
	t_vm			*file;

	file = vm->file;
	while (file)
	{
		read_file(file);
		file = file->next;
	}
}
