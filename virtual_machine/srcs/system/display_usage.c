/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:08:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 21:12:55 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			do_corewar_logo(void)
{
	usleep(100000);
	ft_printf(RED);
	ft_printf("_________                 ___       __             \n");
	usleep(100000);
	ft_printf(CYAN);
	ft_printf("__  ____/___________________ |     / /_____ ________\n");
	usleep(100000);
	ft_printf(YELLOW);
	ft_printf("_  /    _  __ \\_  ___/  _ \\_ | /| / /_  __ `/_  ___/\n");
	usleep(100000);
	ft_printf(GREEN);
	ft_printf("/ /___  / /_/ /  /   /  __/_ |/ |/ / / /_/ /_  /    \n");
	usleep(100000);
	ft_printf(PINK);
	ft_printf("\\____/  \\____/\\/_/    \\___/____/|__/  \\___/ /_/     \n");
	usleep(100000);
	ft_printf(WHITE);
	ft_printf("                               VIRTUAL MACHINE\n");
	ft_printf(RESET);
}

static void			do_usage(void)
{
	ft_printf(B_PINK);
	usleep(100000);
	ft_printf("\n");
	usleep(100000);
	ft_printf("\n");
	usleep(100000);
	ft_printf("USAGE\n");
	ft_printf(RESET);
	ft_printf(PINK);
	usleep(100000);
	ft_printf("$> ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	ft_printf(B_PINK);
	usleep(100000);
}

void				display_usage()
{
	do_corewar_logo();
	do_usage();
}
