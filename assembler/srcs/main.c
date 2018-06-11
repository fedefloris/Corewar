/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:35:56 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/11 15:53:51 by mfiguera         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int		fd;
	t_frame	*frame;
	t_line	*tmp;
		t_label *label1;
		t_label *label2;
		t_list	*binary;

	if (ac != 2)
		return (ft_printf("Usage: %s <sourcefile.s>\n", av[0]));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_printf("Can not open file: %s\n", av[1]));
	if (!ft_initframe(&frame))
		return (ft_printf("ERROR\n"));
	ft_input(fd, frame);
	if (close(fd) == -1)
		return (ft_printf("Can not process file\n"));
	tmp = frame->lines;
	// while (tmp)
	// {
	// 	ft_printf("%s: %s %s,%s,%s %d%d%d\n", tmp->label, tmp->opname, tmp->param[0], tmp->param[1], tmp->param[2], tmp->param_type[0], tmp->param_type[1], tmp->param_type[2]);
		binary = tmp->bytecode;
	// 	while (binary)
	// 	{
	// 		ft_printf("%c", ((char*)binary->content)[0]);
	//		binary = binary->next;
	// 	}
	// 	tmp = tmp->next;
	// }
	label1 = frame->request;
	// while (label1)
	// {
	// 	ft_printf("request:%s\n", label1->name);
	// 	label1 = label1->next;
	// }
	label2 = frame->declare;
	// while (label2)
	// {
	// 	ft_printf("decl:%s\n", label2->name);
	// 	label2 = label2->next;
	// }
	ft_error_output(frame->errors);
	ft_free_frame(&frame);
	return (0);
}
