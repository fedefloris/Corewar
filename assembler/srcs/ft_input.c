/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:26 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/21 23:20:51 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static char	*ft_valid_line(char *s, t_frame *frame, int nb)
{
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	if (!(str = ft_strtrim(s)))
		return (ft_strdup("Failed to malloc trimmed line"));
	ret = NULL;
	if (!frame->lines && ft_strncmp(str, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)) == 0)
		ret = ft_header(str, 1, frame);
	else if (!frame->lines && ft_strncmp(str, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
		ret = ft_header(str, 0, frame);
	else if (*str != '\0' && *str != COMMENT_CHAR)
	{
		if (!frame->lines && (!frame->header || !frame->name ||
				!frame->comt))
			ft_error(ft_strdup(s), ft_strdup("No name or comment"), nb,
					&frame->errors);
		ret = ft_line(str, frame);
	}
	ft_strdel(&str);
	return (ret);
}

int			ft_input(int fd, t_frame *frame)
{
	char	*str;
	int		ret;
	int		line_nb;
	char	*err_msg;
	int		nb;

	ret = 0;
	line_nb = 1;
	while ((nb = get_next(fd, &str, '\n')))
	{
		if ((err_msg = ft_valid_line(str, frame, line_nb)))
			ret += ft_error(ft_strdup(str), err_msg, line_nb, &frame->errors);
		else if (str && (err_msg = ft_produce_line(frame, str, line_nb)))
			ret += ft_error(ft_strdup(str), err_msg, line_nb, &frame->errors);
		ft_strdel(&str);
		line_nb++;
		if (ret > 19)
			return (ret);
	}
	if (str && str[0] != '\0' && ++ret)
		ft_error(ft_strdup(str), ft_strdup("No empty line at end of file"),
			line_nb, &frame->errors);
	ft_strdel(&str);
	return (ret);
}
