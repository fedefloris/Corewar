/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:07:57 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/17 16:50:41 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	ft_output_header(int fd, char *s, int len, int n_val)
{
	char	out;
	int		i;

	i = 0;
	while (i < 4)
	{
		out = (n_val & (0xff << ((8 * (3 - i))))) >> ((8 * (3 - i)));
		ft_putchar_fd(out, fd);
		i++;
	}
	while (len >= 0)
	{
		if (*s)
			ft_putchar_fd(*s++, fd);
		else
			ft_putchar_fd(0, fd);
		len--;
	}
}

static void	ft_output(int fd, t_frame *f, t_op *op)
{
	t_line	*line;
	t_list	*tmp;
	int		i;

	line = f->lines;
	ft_output_header(fd, f->header->prog_name, PROG_NAME_LENGTH + 3,
		COREWAR_EXEC_MAGIC);
	ft_output_header(fd, f->header->comment, COMMENT_LENGTH + 3, f->bytecount);
	while (line)
	{
		i = 0;
		while (i < line->param_count)
			ft_get_arg_byte(line, i++, op[line->opcode - 1].half_size,
				f->request);
		tmp = line->bytecode;
		while (tmp)
		{
			ft_putchar_fd(((char*)tmp->content)[0], fd);
			tmp = tmp->next;
		}
		line = line->next;
	}
}

static char	*ft_get_path(char *name, char *dest)
{
	char	*tmp;
	char	*path;
	char	*n;

	path = name;
	while ((tmp = ft_strchr(name, '/')))
		name = ++tmp;
	n = name;
	while ((tmp = ft_strchr(name, '.')))
		name = ++tmp;
	*(name - 1) = '\0';
	if (!dest)
		name = ft_strjoin(path, ".cor");
	else
	{
		name = ft_strjoin(dest, "/");
		name = ft_strjoinfree(name, name, n);
		name = ft_strjoinfree(name, name, ".cor");
	}
	return (name);
}

int			ft_write_file(t_frame *f, t_op *op, char *name, char *dest)
{
	int		fd;
	int		ret;

	name = ft_get_path(name, dest);
	ret = 1;
	if (ret && (fd = open(name, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IROTH)) == -1)
		ret = 0;
	if (!ret)
	{
		ft_strdel(&name);
		return (0);
	}
	ft_output(fd, f, op);
	ft_printf("Writing to %s\n", name);
	ft_strdel(&name);
	return (1);
}

void		ft_error_output(t_error *error)
{
	t_error *tmp;
	t_error *err;

	err = error;
	while (err->next)
	{
		if (err->line_nb > err->next->line_nb)
		{
			tmp = err;
			err = err->next;
			err->next = tmp;
			err = error;
			continue;
		}
		err = err->next;
	}
	while (error)
	{
		ft_printf("$red$Error$eoc$: %s at line $blue$%d$eoc$\n", error->description, error->line_nb);
		ft_printf("\t$green$\"$eoc$%s$eoc$$green$\"$eoc$\n\n", error->line);
		error = error->next;
	}
}
