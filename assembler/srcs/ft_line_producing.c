/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_producing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:26:41 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/16 18:43:58 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	ft_get_opcode(char *opname)
{
	int	i;

	i = 0;
	while (i < 16 && ft_strcmp(g_op_tab[i].opname, opname))
		i++;
	if (i < 16)
		return (g_op_tab[i].opcode);
	return (0);
}

static int	ft_check_empty(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*label;
	char	*ret;

	if (!str)
		return (1);
	tmp = ft_strtrim(str);
	tmp2 = tmp;
	label = NULL;
	ret = ft_get_label(&tmp, &label);
	if (label)
		ft_strdel(&label);
	if (ret)
		ft_strdel(&ret);
	if (!tmp || !*tmp || *tmp == COMMENT_CHAR)
	{
		ft_strdel(&tmp2);
		return (1);
	}
	ft_strdel(&tmp2);
	return (0);
}

char		*ft_produce_line(t_frame *f, char *str, int line_nb)
{
	t_line	*line;
	int		i;

	if ((!(i = 0) && !f->lines) || ft_check_empty(str))
		return (NULL);
	line = f->lines->last;
	if (!line || !(line->opcode = ft_get_opcode(line->opname)))
		return (ft_strdup("Operation name does not match any operation"));
	if (line->param_count != g_op_tab[line->opcode - 1].param_count)
		return (ft_strdup("Invalid number of params for this operation"));
	while (i < line->param_count)
	{
		if ((line->param_type[i] & g_op_tab[line->opcode - 1].param_type[i])
			!= line->param_type[i])
			return (ft_strdup("Argument type does not match"));
		if (ft_strchr(line->param[i++], LABEL_CHAR))
			ft_push_request(ft_strchr(line->param[i - 1], LABEL_CHAR) + 1,
			&f, str, line_nb);
	}
	if (!ft_line_bytes(line, g_op_tab[line->opcode - 1], f))
		return (ft_strdup("Failed to allocate bytecode"));
	return (NULL);
}
