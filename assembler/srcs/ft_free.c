#include "assembler.h"

void	ft_free_lines(t_line *line)
{
	t_line	*tmp;
	int		i;

	while (line)
	{
		i = 0;
		tmp = line;
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
		line = line->next;
		free(tmp);
	}
}

void	ft_free_header(t_header *header)
{
	if (header->prog_name)
		ft_strdel(&header->prog_name);
	if (header->comment)
		ft_strdel(&header->comment);
	free(header);
}

void	ft_free_frame(t_frame *frame)
{
	if (frame->header)
		ft_free_header(frame->header);
	if (frame->lines)
		ft_free_lines(frame->lines);
	free(frame);
}
