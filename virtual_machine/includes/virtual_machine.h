/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:58:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/04 21:33:35 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include "libft.h"

typedef struct			s_byte_code
{
	int					byte;
	struct s_byte_code	*next;
}						t_byte_code;

typedef struct			s_parser
{
	struct byte_code	*byte_code;
	struct s_parser		*next;
}						t_parser;

typedef struct			s_vm
{
	char				**argv;
	
	struct s_parser		*parser;
}						t_vm;

#endif
