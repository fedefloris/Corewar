/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 00:08:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/12 16:15:28 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"


char	ft_get_acb_byte(t_line *line)
{
	char	byte;
	int		i;
	int		value;

	i = 0;
	byte = 0;
	while (i < 3 && line->param_type[i])
	{
		value = (line->param_type[i] == T_REG) ? REG_CODE : value;
		value = (line->param_type[i] == T_IND) ? IND_CODE : value;
		value = (line->param_type[i] == T_DIR) ? DIR_CODE : value;
		byte = byte | (value << (6 - i * 2));
		i++;
	}
	return (byte);
}

int		ft_get_arg_val(char *param, int param_type, t_label *req)
{
	char *label;

	if ((label = ft_strchr(param, LABEL_CHAR)))
	{
		++label;
		while (req)
		{
			if (!ft_strcmp(req->name, label) && !req->used)
			{
				req->used = 1;
				return (req->dist);
			}
			req = req->next;
		}
	}
	if (param_type == T_IND)
		return (ft_atoi(param));
	else
		return (ft_atoi(param + 1));
}

int		ft_get_nb_bytes(int param_type, int half)
{
	if (param_type == T_DIR)
		return (half ? 2 : 4);
	else if (param_type == T_REG)
		return (1);
	else if (param_type == T_IND)
		return (half ? 2 : 2);
	return (0);
}

void	ft_get_arg_byte(t_line *line, int nb, int half, t_label *req)
{
	unsigned int	val;
	unsigned int	mask;
	int				i;
	char			out;
	int				max;

	val = (unsigned int)ft_get_arg_val(line->param[nb], line->param_type[nb],
			req);
	mask = 0xff;
	i = 0;
	max = ft_get_nb_bytes(line->param_type[nb], half);
	while (i < max && i < 4)
	{
		out = (val & (mask << ((8 * (max - 1 - i))))) >> ((8 * (max - 1 - i)));
		ft_lstappend(&line->bytecode, ft_lstcpy(ft_strdup(&out), 1));
		i++;
	}
}

int		ft_line_bytes(t_line *line, t_op op, t_frame *f)
{
	int		bytecount;
	char	byte;
	int		i;

	bytecount = 0;
	line->bytecode = NULL;
	if (!ft_push_bytecode(&line->bytecode, line->opcode))
		return (0);
	bytecount++;
	if (op.acb)
	{
		byte = ft_get_acb_byte(line);
		if (!ft_push_bytecode(&line->bytecode, byte))
			return (0);
		bytecount++;
	}
	i = 0;
	while (i < line->param_count)
	{
		bytecount += ft_get_nb_bytes(line->param_type[i], op.half_size);
		i++;
	}
	f->bytecount += bytecount;
	return (1);
}
