/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:00:12 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/10 22:07:21 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*ft_get_label(char **s, char **label)
{
	int	i;

	i = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == LABEL_CHAR && i)
	{
		if (!(*label = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(*s + i++))))
			return (ft_strdup("Failed to malloc label"));
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
	}
	if (!i)
		return (ft_strdup("Label starts with a char not in LABEL_CHARS"));
	return (NULL);
}

char	*ft_get_opname(char **s, char **opname)
{
	int	i;

	i = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == DIRECT_CHAR || ft_isspace(s[0][i]))
	{
		if (!(*opname = ft_strsub(*s, 0, ft_strlen(*s) - ft_strlen(*s + i++))))
			return (ft_strdup("Failed to malloc operation name"));
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
		if (**s != SEPARATOR_CHAR)
			return (NULL);
	}
	return (ft_strdup("Invalid character after operation name"));
}

char	*ft_get_arguments(char *s, t_line *line)
{
	char	**arg;
	int		len;
	char	*ret;

	ret = NULL;
	if (!(arg = ft_strsplit(s, SEPARATOR_CHAR)))
		return (ft_strdup("Failed to malloc parameters"));
	if ((len = ft_argno(arg)) > 3)
		ret = ft_strdup("Too many parameters");
	else
		line->param_count = len;
	while (!ret && len--)
	{
		if ((line->param_type[len] = ft_valid_arg(arg[len])))
			line->param[len] = ft_strtrim(arg[len]);
		else
			ret = ft_strdup("Invalid parameter formatting");
		ft_strdel(&arg[len]);
	}
	free(arg);
	return (ret);
}
