/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:09:55 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/14 21:42:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

char				decode_byte(t_vm *vm, unsigned char encoded, int pair)
{
	if (pair < 1 || pair > 4)
		error_exit(vm, "Error decoding encoded byte");
	if (pair == 2)
		encoded <<= 2;
	if (pair == 3)
		encoded <<= 4;
	if (pair == 4)
		encoded <<= 6;
	encoded >>= 6;
	return (encoded);
}
