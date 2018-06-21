/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/21 15:29:57 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

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
		ft_printf("^2^<%s> is not a correct file type\n", file);
		return (-1);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("^2^Can not open file <%s>\n", file);
		return (-1);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	int		fd;
	t_frame	*frame;

	if (ac != 2 && ac != 3)
		return (ft_printf("Usage: %s <sourcefile.s> [dest path]\n", av[0]));
	if ((fd = ft_open(av[1])) == -1)
		return (0);
	if (!ft_initframe(&frame))
		return (ft_printf("^2^$red$Error$eoc$: Failed to initialize frame\n"));
	ft_input(fd, frame);
	ft_fill_dist(frame->request, frame->declare, &frame->errors);
	if (close(fd) == -1)
		return (ft_printf("^2^$red$Error$eoc$: Could not process file\n"));
	if (!frame->errors)
	{
		if (!frame->lines)
			return (ft_printf("^2^$red$Error$eoc$: <%s> is empty or not a file\n", av[1]));
		if (!ft_write_file(frame, g_op_tab, av[1], (ac == 3) ? av[2] : NULL))
			return (ft_printf("^2^$red$Error$eoc$: Creating .cor file stopped\n"));
	}
	else
		ft_error_output(frame->errors);
	ft_free_frame(&frame);
	return (0);
}
