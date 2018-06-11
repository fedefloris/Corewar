/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:49:30 by akaseris          #+#    #+#             */
/*   Updated: 2018/06/11 16:05:03 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*ft_initline(t_line **line)
{
	if (!(*line = (t_line*)malloc(sizeof(t_line))))
		return (ft_strdup("Failed to malloc s_line struct"));
	(*line)->label = NULL;
	(*line)->opname = NULL;
	(*line)->opcode = 0;
	(*line)->param[0] = NULL;
	(*line)->param[1] = NULL;
	(*line)->param[2] = NULL;
	(*line)->param_type[0] = 0;
	(*line)->param_type[1] = 0;
	(*line)->param_type[2] = 0;
	(*line)->param_count = 0;
	(*line)->next = NULL;
	(*line)->last = NULL;
	return (NULL);
}

void	ft_push_line(t_line *line, t_frame *frame)
{
	t_line	*tmp;

	if (!frame->lines)
		frame->lines = line;
	else
	{
		tmp = frame->lines->last;
		tmp->next = line;
	}
	frame->lines->last = line;
}

char	*ft_init_label(t_label **label, char *name, int dist)
{
	if (!(*label = (t_label*)malloc(sizeof(t_label))))
		return (ft_strdup("Failed to malloc label declaration"));
	if (!((*label)->name = name))
	{
		free(*label);
		return (ft_strdup("Failed to malloc label declaration name"));
	}
	(*label)->dist = dist;
	(*label)->next = NULL;
	return (NULL);
}

char	*ft_push_decl(char *name, int dist, t_frame **frame)
{
	t_label	*label;
	t_label *tmp;
	char	*ret;

	if ((ret = ft_init_label(&label, ft_strdup(name), dist)))
		return (ret);
	if (!(*frame)->declare)
		(*frame)->declare = label;
	else
	{
		tmp = (*frame)->declare;
		while (tmp->next)
		{
			if (!ft_strcmp(tmp->name, label->name) ||
				!ft_strcmp(tmp->next->name, label->name))
			{
				ft_free_label(&label);
				return (ft_strdup("Double declaration of label"));
			}
			tmp = tmp->next;
		}
		tmp->next = label;
	}
	return (NULL);
}

char	*ft_push_request(char *name, int dist, t_frame **frame)
{
	t_label	*label;
	t_label *tmp;
	char	*ret;

	if ((ret = ft_init_label(&label, ft_strdup(name), dist)))
		return (ret);
	if (!(*frame)->request)
		(*frame)->request = label;
	else
	{
		tmp = (*frame)->request;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = label;
	}
	return (NULL);
}
