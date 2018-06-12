/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 00:08:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/12 13:00:36 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	ft_get_acb_byte(t_line *line)
{
	char	byte;
	int		value1;
	int		value2;
	int		value3;

	value1 = 0;
	value2 = 0;
	value3 = 0;
	value1 = (line->param_type[0] == T_REG) ? REG_CODE : value1;
	value1 = (line->param_type[0] == T_IND) ? IND_CODE : value1;
	value1 = (line->param_type[0] == T_DIR) ? DIR_CODE : value1;
	value2 = (line->param_type[1] == T_REG) ? REG_CODE : value2;
	value2 = (line->param_type[1] == T_IND) ? IND_CODE : value2;
	value2 = (line->param_type[1] == T_REG) ? REG_CODE : value2;
	value3 = (line->param_type[2] == T_REG) ? REG_CODE : value3;
	value3 = (line->param_type[2] == T_IND) ? IND_CODE : value3;
	value3 = (line->param_type[2] == T_DIR) ? DIR_CODE : value3;
	byte = value1 << 6;
	if (line->param_count >= 2)
		byte = byte | value2 << 4;
	if (line->param_count == 3)
		byte = byte | value3 << 2;
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
			if (!ft_strcmp(req->name, label))
				return (req->dist);
			req = req->next;
		}
	}
	if (param_type == IND_CODE)
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
		return (half ? 1 : 2);
	return (0);
}

void	ft_get_arg_byte(t_line *line, int nb, int half, t_label *req)
{
	unsigned int	val;
	unsigned int	mask;
	int				i;
	char			out;
	int				max;

	if (ft_strchr(line->param[nb], LABEL_CHAR))
		return ;
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
