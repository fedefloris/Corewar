/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/07 18:57:43 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_get_label(char **s, char **label)
{
	int	i;

	i = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == LABEL_CHAR && i)
	{
		if (!(*label = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(*s + i++))))
			return (0);
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
	}
	if (!i)
		return (0);
	return (1);
}

int		ft_get_opname(char **s, char **opname)
{
	int	i;

	i = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == DIRECT_CHAR || ft_isspace(s[0][i]))
	{
		if (!(*opname = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(*s + i++))))
			return (0);
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
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

int		ft_valid_arg(char *s)
{
	int		i;

	i = 0;
	while (*s && ft_isspace(s[i]))
		s++;
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
		if (!s[i] && i && ft_isdigit(s[i - 1]))
			return (1);
	}
	return (0);
}

int		ft_get_arguments(char *s, t_line *line)
{
	char	**arg;
	int		len;
	int		ret;

	ret = 1;
	if (!(arg = ft_strsplit(s, SEPARATOR_CHAR)))
		return (0);
	if ((len = ft_argno(arg)) > 3)
		ret = 0;
	while (ret && len--)
	{
		if (ft_valid_arg(arg[len]))
			line->param[len] = ft_strtrim(arg[len]);
		else
			ret = 0;
		ft_strdel(&arg[len]);
	}
	free(arg);
	return (ret);
}
