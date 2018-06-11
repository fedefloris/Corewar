/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_producing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:26:41 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/11 16:08:27 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		ft_get_opcode(char *opname)
{
	int	i;

	i = 0;
	while (i < 16 && ft_strcmp(g_op_tab[i].opname, opname))
		i++;
	if (i < 16)
		return (g_op_tab[i].opcode);
	return (0);
}

char	*ft_produce_line(t_frame *f)
{
	t_line	*line;
	int		i;
	char	*ret;

	if (!(i = 0) && !f->lines)
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
				f->bytecount, &f);
	}
	if (line->label && (ret = ft_push_decl(line->label, f->bytecount, &f)))
		return (ret);
	if (!ft_line_bytes(line, &g_op_tab[line->opcode - 1]))
		return (ft_strdup("Failed to allocate bytecode"));
	return (NULL);
}
