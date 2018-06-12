/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:09:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/13 00:59:29 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

char				decode_byte(t_vm *vm, unsigned char *encoded, int pair)
{
	unsigned char	byte;

	byte = *encoded;
	if (pair < 1 || pair > 4)
		error_exit(vm, "Error decoding encoded byte");
	if (pair == 2)
		byte <<= 2;
	if (pair == 3)
		byte <<= 4;
	if (pair == 4)
		byte <<= 6;
	byte >>= 6;
	return (byte);
}
