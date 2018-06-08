/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 23:27:38 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/09 00:36:12 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				error_exit(t_vm *vm, char *string)
{
	ft_putstr(string);
	ft_putstr("\n");
	free_virtual_machine(vm);
	exit(1);
}
