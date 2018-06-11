/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 00:08:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/11 14:41:25 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_push_bytecode(t_list **bytecode, char c)
{
	t_list	*tmp;
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	new->content = ft_strdup(&c);
	new->content_size = 1;
	new->next = NULL;
	tmp = *bytecode;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*bytecode = new;
	return (1);
}

char	ft_get_acb_byte(t_line *line)
{
	char	byte;

	byte = line->param_type[0] << 6;
	if (line->param_count >= 2)
		byte = byte | line->param_type[1] << 4;
	if (line->param_count == 3)
		byte = byte | line->param_type[2] << 2;
	return (byte);
}

int		ft_line_bytes(t_line *line, t_op *op)
{
	int		bytecount;
	char	byte;

	bytecount = 0;
	line->bytecode = NULL;
	if (!ft_push_bytecode(&line->bytecode, line->opcode))
		return (0);	
	bytecount++;
	if (op->acb)
	{
		byte = ft_get_acb_byte(line);
		if (!ft_push_bytecode(&line->bytecode, byte))
			return (0);
		bytecount++;
	}
	//fill the remaining parameter bytes
	return (1);
}
