/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:09:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 00:29:59 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "virtual_machine.h"

#include <unistd.h>
void				decode_byte(const char *encoded_byte, int bit_pair)
{
	char			byte;

	byte = *encoded_byte;
	if (bit_pair < 1 || bit_pair > 4)
		write(1, "Error\n", 6);
//		error_exit("Error decoding encoded byte");
	if (bit_pair == 2)
		byte <<= 2;
	if (bit_pair == 3)
		byte <<= 4;
	if (bit_pair == 4)
		byte <<= 6;
	byte >>= 6;
}
