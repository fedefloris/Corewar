/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:39:18 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/10 15:32:42 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				usage(t_vm *vm, int i)
{
	//Actually write a real usage.
	ft_putstr("This is usage\n");
	free_vm(vm);
	exit(i);
}
