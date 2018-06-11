/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:08:07 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/11 11:28:38 by dhojt            ###   ########.fr       */
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
	ft_printf("                                             USAGE\n");
	ft_printf(RESET);
}

//static void			do_read(void)
//{
//	ft_printf(B_PINK);
//	usleep(100000);
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("READ FILE\n");
//	ft_printf(RESET);
//	ft_printf(PINK);
//	usleep(100000);
//	ft_printf("$>./lem-in < maps/test1.map\n");
//	ft_printf(B_PINK);
//	usleep(100000);
//}
//
//static void			do_stdin(void)
//{
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("STDIN\n");
//	ft_printf(RESET);
//	ft_printf(PINK);
//	usleep(100000);
//	ft_printf("$>./lem-in\n");
//	usleep(100000);
//	ft_printf("13\n");
//	usleep(100000);
//	ft_printf("##start\n");
//	usleep(100000);
//	ft_printf("Room42 21 42\n");
//	usleep(100000);
//	ft_printf("#comment\n");
//	usleep(100000);
//	ft_printf("##end\n");
//	usleep(100000);
//	ft_printf("Room27 27 11\n");
//	usleep(100000);
//	ft_printf("Room1-Room42\n");
//	usleep(100000);
//	ft_printf("Room42-Room27\n");
//}
//
//static void			do_flags(void)
//{
//	ft_printf(B_PINK);
//	usleep(100000);
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("\n");
//	usleep(100000);
//	ft_printf("FLAGS\n");
//	ft_printf(RESET);
//	ft_printf(PINK);
//	usleep(100000);
//	ft_printf("$>./lem-im [-d | -r | -p | -l | -all] [file]\n");
//	usleep(100000);
//	ft_printf(" -d   Debug\n");
//	usleep(100000);
//	ft_printf(" -r   Rooms\n");
//	usleep(100000);
//	ft_printf(" -p   Path\n");
//	usleep(100000);
//	ft_printf(" -l   Links\n");
//	usleep(100000);
//	ft_printf(" -all Show all\n");
//}

void				display_usage(t_vm *vm, int i)
{
	do_corewar_logo();
//	do_read();
//	do_stdin();
//	do_flags();
	free_virtual_machine(vm);
	exit(i);
}
