/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:31:39 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/11 13:37:49 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_free_errors(t_error **errors)
{
	t_error	*tmp;
	t_error *error;

	error = *errors;
	while (error)
	{
		tmp = error;
		if (error->description)
			ft_strdel(&error->description);
		if (error->line)
			ft_strdel(&error->line);
		error = error->next;
		free(tmp);
	}
	*errors = NULL;
}

void	ft_free_lines(t_line **lines)
{
	t_line	*line;
	t_line	*tmp;
	int		i;

	line = *lines;
	while (line != NULL)
	{
		i = 0;
		if (line->label)
			ft_strdel(&line->label);
		if (line->opname)
			ft_strdel(&line->opname);
		while (i < 3)
		{
			if (line->param[i])
				ft_strdel(&line->param[i]);
			i++;
		}
		tmp = line;
		line = line->next;
		free(tmp);
	}
	*lines = NULL;
}

void	ft_free_header(t_header **headers)
{
	t_header	*header;

	header = *headers;
	if (header->prog_name)
		ft_strdel(&header->prog_name);
	if (header->comment)
		ft_strdel(&header->comment);
	free(header);
	*headers = NULL;
}

void	ft_free_label(t_label **labels)
{
	t_label *label;
	t_label *tmp;

	label = *labels;
	while (label)
	{
		tmp = label;
		if (label->name)
			ft_strdel(&label->name);
		label = label->next;
		free(tmp);
	}
	*labels = NULL;
}

void	ft_free_frame(t_frame **frames)
{
	t_frame	*frame;

	frame = *frames;
	if (frame->header)
		ft_free_header(&frame->header);
	if (frame->lines)
		ft_free_lines(&frame->lines);
	if (frame->errors)
		ft_free_errors(&frame->errors);
	if (frame->declare)
		ft_free_label(&frame->declare);
	if (frame->request)
		ft_free_label(&frame->request);
	free(frame);
	*frames = NULL;
}
