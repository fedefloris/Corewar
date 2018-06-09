/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:49:30 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/07 17:55:30 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_initline(t_line **line)
{
	if (!(*line = (t_line*)malloc(sizeof(t_line))))
		return (0);
	(*line)->label = NULL;
	(*line)->opname = NULL;
	(*line)->param[0] = NULL;
	(*line)->param[1] = NULL;
	(*line)->param[2] = NULL;
	(*line)->next = NULL;
	(*line)->prev = NULL;
	return (1);
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
