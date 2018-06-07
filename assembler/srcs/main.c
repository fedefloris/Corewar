/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 18:59:44 by akaseris         ###   ########.fr       */
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
	(*frame)->bytecount = 0;
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_frame	*frame;

	if (ac != 2)
		return (ft_printf("ERROR\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_printf("Can not process file\n"));
	if (!ft_initframe(&frame))
		return (ft_printf("ERROR\n"));
	if (!ft_input(fd, &frame))
		return (ft_printf("ERROR\n"));
	if (close(fd) == -1)
		return (ft_printf("Can not process file\n"));
//	ft_printf("***%s***\n***%s***\n", (frame)->lines->prog_name, (frame)->header->comment);
	return (0);
}
