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

int		ft_valid_arg(char *s)
{
	int		i;

	i = 0;
	while (s && ft_isspace(s[i]))
		i++;
	s += i;
	i = 0;
	if (s[i] == DIRECT_CHAR && s[i + 1] == LABEL_CHAR)
	{
		i += 2;
		while (ft_strchr(LABEL_CHARS, s[i]) && s[i])
			i++;
		if (s[i] == '\0')
			return (1);
	}
	else if ((ft_isdigit(s[i]) || s[i] == 'r' || s[i] == DIRECT_CHAR))
	{
		if (s[i] == 'r' || s[i] == DIRECT_CHAR)
			i++;
		if (s[i] == '-')
			i++;
		while (ft_isdigit(s[i]))
			i++;
		if (!s[i] && i > 1)
			return (1);
	}
	return (0);
}

int		ft_argno(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		i++;
	return (i);
}

int		ft_line2(char *s, t_frame **frame, t_line *line)
{
	char	**arg;
	int		len;
	int		ret;
	t_line	*tmp2;

	ret = 1;
	ft_printf("%s", s);
	if (!(arg = ft_strsplit(s, SEPARATOR_CHAR)))
		ret = 0;
	if ((len = ft_argno(arg)) > 3)
		ret = 0;
	while (ret && len--)
	{
		if (ft_valid_arg(arg[len]))
			line->param[len] = arg[len];
		else
			ret = 0;
	}
	// if (!ret)
	// {
	// 	while (len--)
	// 		ft_strdel(&arg[len]);
	// }
	if (ret)
	{
		if ((*frame)->lines)
		{
			tmp2 = (*frame)->lines;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = line;
		}
	}
	//free(arg);
	ft_strdel(&s);
	return (ret);
}

int		ft_line(char *s, t_frame **frame)
{
	t_line	*line;
	int		i;
	char	*tmp;

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
	s = s + i;
	if ((tmp = ft_strchr(s, COMMENT_CHAR)))
	{
		tmp[0] = '\0';
		if (*(tmp - 1) == SEPARATOR_CHAR)
			return (0);
	}
	ft_printf("<%s>\n<%s>\n", line->label, line->opname);
	return (ft_line2(ft_strtrim(s), frame, line));
}
