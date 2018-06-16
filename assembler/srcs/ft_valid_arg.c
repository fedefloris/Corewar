/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:26:08 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/16 17:52:44 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	ft_valid_registry(char *s)
{
	int	i;
	int	val;

	i = 0;
	if (s[i] == 'r')
	{
		val = ft_atoi(&s[1]);
		while (ft_isdigit(s[++i]))
			(void)i;
		if (i != 1 && !s[i] && val && val <= REG_NUMBER)
			return (1);
	}
	return (0);
}

static int	ft_valid_direct(char *s)
{
	int	i;

	i = 0;
	if (s[i] == DIRECT_CHAR)
	{
		if (s[++i] == LABEL_CHAR)
		{
			i++;
			while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
				i++;
		}
		else if (ft_isdigit(s[i]) || s[i++] == '-')
		{
			while (ft_isdigit(s[i]))
				i++;
		}
		if (!s[i] && i > ((s[1] == LABEL_CHAR) ? 2 : 1))
			return (1);
	}
	return (0);
}

static int	ft_valid_indirect(char *s)
{
	int	i;

	i = 0;
	if (ft_isdigit(s[i]) || s[i] == LABEL_CHAR || s[i] == '-')
	{
		if (s[i] == LABEL_CHAR)
		{
			i++;
			while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
				i++;
		}
		else if (ft_isdigit(s[i]) || s[i++] == '-')
		{
			while (ft_isdigit(s[i]))
				i++;
		}
		if (!s[i] && i > ((s[1] == LABEL_CHAR || s[1] == '-') ? 1 : 0))
			return (1);
	}
	return (0);
}

int			ft_valid_arg(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (ft_valid_registry(s))
		return (T_REG);
	else if (ft_valid_direct(s))
		return (T_DIR);
	else if (ft_valid_indirect(s))
		return (T_IND);
	else
		return (0);
}

int			ft_argno(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		i++;
	return (i);
}
