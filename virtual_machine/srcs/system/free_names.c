/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:36:47 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/17 17:36:49 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void		free_names(t_name *names)
{
	t_name		*prev;

	while (names)
	{
		prev = names;
		names = names->next;
		free(prev);
	}
}
