/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:58:20 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/19 15:00:35 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

/*
** Function fetches correct value based on DIR, IND, REG.
*/

void	get_reg_value(t_process *ps, unsigned char encoded, int *parameter)
{
	if (encoded == REG_CODE)
		*parameter = ps->r[get_r(*parameter % 256)];
}
