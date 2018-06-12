/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:07:57 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/12 13:48:36 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_error_output(t_error *error)
{
	while (error)
	{
		ft_printf("Error: %s at line %d\n", error->description, error->line_nb);
		ft_printf("\t\"%s\"\n\n", error->line);
		error = error->next;
	}
}

void	ft_output(int fd, t_frame *f, t_op *op)
{
	t_line	*line;
	t_list	*tmp;
	int		i;

	line = f->lines;
	while (line)
	{
		i = 0;
		while (i < line->param_count)
			ft_get_arg_byte(line, i++, op[line->opcode - 1].half_size, f->request);
		tmp = line->bytecode;
		while (tmp)
		{
			ft_putchar_fd(((char*)tmp->content)[0], fd);
			tmp = tmp->next;
		}
		ft_putchar_fd(0xaa, fd);
		line = line->next;
	}
}