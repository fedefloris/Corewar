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
