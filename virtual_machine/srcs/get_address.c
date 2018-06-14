/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:47:14 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 20:57:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				get_address(t_process *ps, int modify, int *address)
{
	*address = ps->pc + modify;
	if (*address > 0)
		*address %= MEM_SIZE;
	else if (*address < 0)
		*address = (*address % MEM_SIZE) + MEM_SIZE;
}
