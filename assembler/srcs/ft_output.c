/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:07:57 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/21 22:54:09 by mfiguera         ###   ########.fr       */
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
		ft_putchar_fd(*s++, fd);
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
		f->header->magic);
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
	ft_printf("Writing to $green$%s$eoc$\n", name);
	ft_strdel(&name);
	return (1);
}

void		ft_error_output(t_frame **frame)
{
	int		count;
	t_error	*error;

	count = 0;
	if (!frame)
		return ;
	ft_sort_errors(&((*frame)->errors));
	error = (*frame)->errors;
	while (error && count < 20)
	{
		ft_printf("^2^$red$Error$eoc$: %s at line $blue$%d$eoc$\n",
			error->description, error->line_nb);
		ft_printf("^2^\t$green$\"$eoc$%s$eoc$$green$\"$eoc$\n\n", error->line);
		error = error->next;
		count++;
	}
	if (count == 20)
		ft_printf("^2^Stopped at 20 errors. Please review your assembly skills\n");
}
