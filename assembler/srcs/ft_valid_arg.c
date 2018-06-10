/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:26:08 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/10 19:35:37 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	ft_valid_registry(char *s)
{
	int	i;

	i = 0;
	if (s[i] == 'r')
	{
		while (ft_isdigit(s[++i]))
			(void)i;
		if (i != 1 && !s[i])
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
	if (ft_isdigit(s[i]) || s[i] == LABEL_CHAR)
	{
		if (s[i] == LABEL_CHAR)
		{
			i++;
			while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
				i++;
		}
		else if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
				i++;
		}
		if (!s[i] && i > ((s[1] == LABEL_CHAR) ? 1 : 0))
			return (1);
	}
	return (0);
}

int			ft_valid_arg(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (ft_valid_registry(s))
		return (1);
	else if (ft_valid_direct(s))
		return (2);
	else if (ft_valid_indirect(s))
		return (3);
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
