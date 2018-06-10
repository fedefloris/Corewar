/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/10 18:48:21 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*ft_valid_line(char *s, t_frame *frame)
{
	char	*str;
	char	*ret;
	char	*namestr;
	char	*commentstr;

	namestr = NAME_CMD_STRING;
	commentstr = COMMENT_CMD_STRING;
	if (!s)
		return (NULL);
	if (!(str = ft_strtrim(s)))
		return (ft_strdup("Failed to malloc trimmed line"));
	ret = NULL;
	if (ft_strncmp(str, namestr, ft_strlen(namestr)) == 0)
		ret = ft_header(str, 1, frame);
	else if (ft_strncmp(str, commentstr, ft_strlen(commentstr)) == 0)
		ret = ft_header(str, 0, frame);
	else if (*str != '\0')
		ret = ft_line(str, frame);
	ft_strdel(&str);
	return (ret);
}

int		ft_input(int fd, t_frame *frame)
{
	char	*str;
	int		ret;
	int		line_nb;
	char	*err_msg;

	ret = 1;
	line_nb = 1;
	while (get_next(fd, &str, '\n'))
	{
		if ((err_msg = ft_valid_line(str, frame)))
		{
			ret = 0;
			ft_error(ft_strdup(str), err_msg, line_nb, &frame->errors);
		}
		ft_strdel(&str);
		line_nb++;
	}
	if (str)
	{
		if (str[0] != '\0' && !(ret = 0))
			ft_error(ft_strdup(str), ft_strdup("No empty line at end of file"),
				line_nb, &frame->errors);
		ft_strdel(&str);
	}
	return (ret);
}
