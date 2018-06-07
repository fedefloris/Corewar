/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:29:35 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/07 19:01:57 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_addheader(char **tmp, int name, t_frame **frame)
{
	t_header *head;

	head = (*frame)->header;
	if (name)
	{
		if (ft_strlen(*tmp) > PROG_NAME_LENGTH || head->prog_name != NULL)
		{
			ft_strdel(tmp);
			return (0);
		}
		head->prog_name = *tmp;
		(*frame)->bytecount += PROG_NAME_LENGTH;
	}
	else
	{
		if (ft_strlen(*tmp) > COMMENT_LENGTH || head->comment != NULL)
		{
			ft_strdel(tmp);
			return (0);
		}
		head->comment = *tmp;
		(*frame)->bytecount += COMMENT_LENGTH;
	}
	return (1);
}

int		ft_header(char *s, int name, t_frame **frame)
{
	int		i;
	char	*tmp;

	i = (name) ? ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(s[i]))
		i++;
	if (s[i++] != '"')
		return (0);
	s = s + i;
	if (!(tmp = ft_strchr(s, '"')))
		return (0);
	tmp++;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp != '\0' && *tmp != COMMENT_CHAR)
		return (0);
	tmp = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '"')));
	return (ft_addheader(&tmp, name, frame));
}

int		ft_line(char *s, t_frame **frame)
{
	t_line	*line;
	int		i;

	(*frame)->bytecount = 0;
	if (!ft_initline(&line))
		return (0);
	i = 0;
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (s[i] == LABEL_CHAR && i)
	{
		line->label = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(s + i++));
		while (ft_isspace(s[i]))
			i++;
		s = s + i;
		i = 0;
	}
	else if (!i)
		return (0);
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (s[i] == DIRECT_CHAR || ft_isspace(s[i]))
		line->opname = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(s + i++));
	else
		return (0);
	while (ft_isspace(s[i]))
		i++;
	s = s + i;
	ft_printf("<%s>\n<%s>\n", line->label, line->opname);
	return (1);
}
