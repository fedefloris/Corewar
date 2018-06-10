/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <mfiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:07:57 by mfiguera          #+#    #+#             */
/*   Updated: 2018/06/10 18:45:30 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_error_output(t_error *error)
{
	while (error)
	{
		ft_printf("Error: %s at line %d\n", error->description, error->line_nb);
		ft_printf("\t\"%s\"\n\n", error->line);
		error = error->next;
	}
}
