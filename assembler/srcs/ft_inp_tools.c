/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inp_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:29:35 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/07 16:14:41 by akaseris         ###   ########.fr       */
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

int		ft_header(char *s, int name, int fd, t_frame **frame)
{
	int		i;
	char	*tmp;
	char	*str;

	i = (name) ? ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(s[i]))
		i++;
	if (s[i++] != '"')
		return (0);
	str = ft_strdup(s + i);
	while (!ft_strchr(str, '"'))
	{
		i = get_next(fd, &tmp, '\n');
		str = ft_strjoinfree(str, str, tmp);
		ft_strdel(&tmp);
		if (!str || !i)
			return (0);
	}
	tmp = ft_strchr(str, '"') + 1;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp != '\0' && *tmp != COMMENT_CHAR)
		return (0);
	tmp = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(ft_strchr(str, '"')));
	return (ft_addheader(&tmp, name, frame));
}

int		ft_line(char *s, t_frame **frame)
{
	s = NULL;
	(*frame)->bytecount = 1;
	return (1);
}
