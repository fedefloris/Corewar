/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:09:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 22:13:05 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

char				decode_byte(unsigned char encoded, int pair)
{
	if (pair == 2)
		encoded <<= 2;
	if (pair == 3)
		encoded <<= 4;
	if (pair == 4)
		encoded <<= 6;
	encoded >>= 6;
	return (encoded);
}
