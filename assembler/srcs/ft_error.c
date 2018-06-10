/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:23:00 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/10 18:45:41 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_initerror(t_error **error)
{
	if (!(*error = (t_error*)malloc(sizeof(t_error))))
		return (0);
	(*error)->description = NULL;
	(*error)->line = NULL;
	(*error)->line_nb = 0;
	(*error)->next = NULL;
	return (1);
}

int		ft_error(char *line, char *msg, int line_nb, t_error **err_list)
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
