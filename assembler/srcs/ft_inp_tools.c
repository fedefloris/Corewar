/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:29:35 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/10 15:26:12 by mfiguera         ###   ########.fr       */
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

int		ft_line(char *s, t_frame *frame)
{
	t_line	*line;
	char	*tmp;
	int		ret;

	ret = 1;
	line = NULL;
	if ((tmp = ft_strchr(s, COMMENT_CHAR)))
		tmp[0] = '\0';
	if (!(s = ft_strtrim(s)))
		return (0);
	if (s[ft_strlen(s) - 1] == SEPARATOR_CHAR)
		ret = 0;
	tmp = s;
	ret = ((ret && !ft_initline(&line)) ? 0 : ret);
	ret = ((ret && !ft_get_label(&s, &line->label)) ? 0 : ret);
	ret = ((ret && !ft_get_opname(&s, &line->opname)) ? 0 : ret);
	ret = ((ret && !ft_get_arguments(s, line)) ? 0 : ret);
	ft_strdel(&tmp);
	if (ret)
		ft_push_line(line, frame);
	else
		ft_free_lines(line);
	return (ret);
}
