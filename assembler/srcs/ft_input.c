/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/06 15:48:57 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_valid_line(char *s)
{
	char	**split;

	if (!s)
		return (1);
	split = ft_strsplit(s, '\t');

}

int		ft_input(int fd)
{
	char	*str;

	while(get_next(fd, &str, '\n'))
	{
		if (!ft_valid_line(str))
		{
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	return ((str) ? 0 : 1);
}
