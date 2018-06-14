/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:10:52 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 22:16:11 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				calc_bytes(unsigned char encoded, int pair, int *bytes)
{
	if (decode_byte(encoded, pair) == REG_CODE)
		*bytes = 1;
	if (decode_byte(encoded, pair) == DIR_CODE)
		*bytes = 4;
	if (decode_byte(encoded, pair) == IND_CODE)
		*bytes = 2;
}
