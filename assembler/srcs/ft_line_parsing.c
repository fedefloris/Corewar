/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:00:12 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/10 18:45:12 by mfiguera         ###   ########.fr       */
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
			return (2);
	}
	else if ((ft_isdigit(s[i]) || s[i] == 'r' || s[i] == DIRECT_CHAR))
	{
		i = (s[i] == 'r' || s[i] == DIRECT_CHAR) ? i + 1 : i;
		i = (s[i] == '-') ? i + 1 : i;
		while (ft_isdigit(s[i]))
			i++;
		if (!s[i] && i && ft_isdigit(s[i - 1]) && s[0] == 'r')
			return (1);
		else if (!s[i] && i && ft_isdigit(s[i - 1]))
			return (s[0] == DIRECT_CHAR ? 2 : 3);
	}
	return (0);
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
