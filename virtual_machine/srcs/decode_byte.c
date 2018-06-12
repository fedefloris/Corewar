/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:09:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 00:51:19 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

char				decode_byte(t_vm *vm, unsigned char *encoded, int bit_pair)
{
	unsigned char	byte;

	byte = *encoded;
	if (bit_pair < 1 || bit_pair > 4)
		error_exit(vm, "Error decoding encoded byte");
	if (bit_pair == 2)
		byte <<= 2;
	if (bit_pair == 3)
		byte <<= 4;
	if (bit_pair == 4)
		byte <<= 6;
	byte >>= 6;
	return (byte);
}
