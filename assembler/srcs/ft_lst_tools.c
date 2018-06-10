/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:49:30 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/10 17:37:25 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*ft_initline(t_line **line)
{
	if (!(*line = (t_line*)malloc(sizeof(t_line))))
		return (ft_strdup("Failed to malloc s_line struct"));
	(*line)->label = NULL;
	(*line)->opname = NULL;
	(*line)->param[0] = NULL;
	(*line)->param[1] = NULL;
	(*line)->param[2] = NULL;
	(*line)->param_type[0] = 0;
	(*line)->param_type[1] = 0;
	(*line)->param_type[2] = 0;
	(*line)->param_count = 0;
	(*line)->next = NULL;
	(*line)->prev = NULL;
	return (NULL);
}

void	ft_push_line(t_line *line, t_frame *frame)
{
	t_line	*tmp;

	if (!frame->lines)
		frame->lines = line;
	else
	{
		tmp = frame->lines;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = line;
	}
}
