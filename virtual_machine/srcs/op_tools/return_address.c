/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:31:19 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/18 11:34:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int				return_address(t_process *ps, int modify)
{
	int address;

	get_address(ps, modify, &address);
	return (address);
}
