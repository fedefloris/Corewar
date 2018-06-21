/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ops_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:27:21 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 18:27:22 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void			free_ops_queue(t_ps_op *ops_queue)
{
	t_ps_op		*prev;

	while (ops_queue)
	{
		prev = ops_queue;
		ops_queue = ops_queue->next;
		free(prev);
	}
}
