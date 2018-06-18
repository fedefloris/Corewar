/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:08:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/18 01:35:20 by dhojt            ###   ########.fr       */
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
	ft_printf("$> ./corewar [-a | -d | -x | -X] [-dump nbr_cycles]");
	ft_printf("[[-n number] champion1.cor] ...\n");
	usleep(100000);
}

static void			do_aff(void)
{
	ft_printf("\n");
	usleep(100000);
	ft_printf("\n");
	usleep(100000);
	ft_printf(B_PINK);
	ft_printf("FLAGS\n");
	ft_printf(RESET);
	ft_printf(PINK);
	usleep(100000);
	ft_printf("-a      Aff (Character with 256 modulo applied).\n");
	usleep(100000);
	ft_printf("-d      Aff (Displayed as decimal).\n");
	usleep(100000);
	ft_printf("-x      Aff (Displayed as hexidecimal (lower case)).\n");
	usleep(100000);
	ft_printf("-X      Aff (Displayed as hexidecimal (upper case)).\n");
	usleep(100000);
	ft_printf("\n");
	usleep(100000);
	ft_printf("-n      Player number selection.\n");
	usleep(100000);
	ft_printf("        Example: > ./corewar -n 42 tasos.cor -n 7 marti.cor\n");
	usleep(100000);
	ft_printf("        Corewar will auto-assign where no selection is made.\n");
	usleep(100000);
}

static void			do_mandatory(void)
{
	ft_printf("\n");
	usleep(100000);
	ft_printf("-dump   Dump memory.\n");
	usleep(100000);
	ft_printf("        Example: > ./corewar -dump 27 dav.cor federico.cor\n");
	usleep(100000);
	ft_printf("        Here, Corewar will dump memory after 42 cycles.\n");
	usleep(100000);
	ft_printf("        Corewar does not accept Bitcoin Cash LOL.\r");
	usleep(300000);
	ft_printf("        Corewar can only accept 1 -dump argument.\n");
}

void				display_usage(void)
{
	ft_printf(CLEAR);
	do_corewar_logo();
	do_usage();
	do_aff();
	do_mandatory();
}
