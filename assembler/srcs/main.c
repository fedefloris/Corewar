/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/16 17:32:43 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_op	g_op_tab2[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		ft_initframe(t_frame **frame)
{
	if (!(*frame = (t_frame*)malloc(sizeof(**frame))))
		return (0);
	if (!((*frame)->header = (t_header*)malloc(sizeof(t_header))))
	{
		free(*frame);
		return (0);
	}
	(*frame)->header->prog_name = NULL;
	(*frame)->header->comment = NULL;
	(*frame)->lines = NULL;
	(*frame)->request = NULL;
	(*frame)->declare = NULL;
	(*frame)->errors = NULL;
	(*frame)->bytecount = 0;
	return (1);
}

int		ft_open(char *file)
{
	int		fd;
	char	*tmp;
	char	*s;

	s = file;
	while ((tmp = ft_strchr(s, '/')))
		s = ++tmp;
	while ((tmp = ft_strchr(s, '.')))
		s = ++tmp;
	if (ft_strcmp(s, "s"))
	{
		ft_printf("<%s> is not a correct file type\n", file);
		return (-1);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Can not open file <%s>\n", file);
		return (-1);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	int		fd;
	t_frame	*frame;

	if (ac != 2)
		return (ft_printf("Usage: %s <sourcefile.s>\n", av[0]));
	if ((fd = ft_open(av[1])) == -1)
		return (0);
	if (!ft_initframe(&frame))
		return (ft_printf("ERROR\n"));
	ft_input(fd, frame);
	ft_fill_dist(frame->request, frame->declare, frame->errors);
	if (close(fd) == -1)
		return (ft_printf("Can not process file\n"));
	if (!frame->errors)
	{
		if (!frame->lines)
			return (ft_printf("ERROR <%s> is empty or not a file\n", av[1]));
		if (!ft_write_file(frame, g_op_tab2, av[1]))
			return (ft_printf("ERROR creating .cor file stopped\n"));
	}
	else
		ft_error_output(frame->errors);
	ft_free_frame(&frame);
	return (0);
}
