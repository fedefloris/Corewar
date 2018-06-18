/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:36:54 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/17 17:36:55 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void		free_byte_code(t_byte_code *byte_code)
{
	t_byte_code		*prev;

	while (byte_code)
	{
		prev = byte_code;
		byte_code = byte_code->next;
		free(prev);
	}
}

static void		free_champ(t_champ *champ)
{
	if (champ->name)
		free(champ->name);
	if (champ->bytes)
		free(champ->bytes);
	free_byte_code(champ->byte_code);
	free(champ);
}

void			free_champs(t_champ *champs)
{
	t_champ			*prev;

	while (champs)
	{
		prev = champs;
		champs = champs->next;
		free_champ(prev);
	}
}
