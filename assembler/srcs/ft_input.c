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

int		ft_valid_line(char *s, t_frame **frame)
{
	char	*str;
	int		ret;
	char	*namestr;
	char	*commentstr;

	namestr = NAME_CMD_STRING;
	commentstr = COMMENT_CMD_STRING;
	if (!s)
		return (1);
	if (!(str = ft_strtrim(s)))
		return (0);
	ret = 1;
	if (ft_strncmp(str, namestr, ft_strlen(namestr)) == 0)
		ret = ft_header(str, 1, frame);
	else if (ft_strncmp(str, commentstr, ft_strlen(commentstr)) == 0)
		ret = ft_header(str, 0, frame);
	else if (*str != '\0')
		ret = ft_line(str, *frame);
	ft_strdel(&str);
	return (ret);
}

int		ft_input(int fd, t_frame **frame)
{
	char	*str;

	while (get_next(fd, &str, '\n'))
	{
		if (!ft_valid_line(str, frame))
		{
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	return ((str) ? 1 : 1);
}
