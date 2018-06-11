/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:47:32 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 12:25:27 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				parse_handler(t_vm *vm)
{
	parse_options(vm);
	parse_create_champ(vm);
	parse_read_champ(vm);
	parse_bytes(vm);
}
