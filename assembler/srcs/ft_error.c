/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:23:00 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/19 14:31:04 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	ft_initerror(t_error **error)
{
	if (!(*error = (t_error*)malloc(sizeof(t_error))))
		return (0);
	(*error)->description = NULL;
	(*error)->line = NULL;
	(*error)->line_nb = 0;
	(*error)->next = NULL;
	return (1);
}

int			ft_error(char *line, char *msg, int line_nb, t_error **err_list)
{
	t_error	*error;
	t_error *tmp;

	if (!ft_initerror(&error))
		return (0);
	error->line = line;
	error->description = msg;
	error->line_nb = line_nb;
	if (!*err_list)
		*err_list = error;
	else
	{
		tmp = *err_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = error;
	}
	return (0);
}

void		ft_sort_errors(t_error **error)
{
	t_error *tmp;
	t_error *err;
	t_error *prev;

	err = *error;
	prev = NULL;
	while (err->next)
	{
		if (err->line_nb > err->next->line_nb)
		{
			tmp = err;
			if (prev)
				prev->next = err->next;
			else
				*error = err->next;
			err = err->next;
			tmp->next = err->next;
			err->next = tmp;
			err = *error;
			prev = NULL;
			continue;
		}
		prev = err;
		err = err->next;
	}
}
