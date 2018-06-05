/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:58:52 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/05 13:52:39 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# define SIZE_OF_BUFF	64

# include "libft.h"
# include <stdio.h>//Remove

typedef struct			s_byte_code
{
	int					byte;
	struct s_byte_code	*next;
}						t_byte_code;

typedef struct			s_file
{
	char				*file_name;
	struct s_byte_code	*byte_code;
	struct s_file		*next;
}						t_file;

typedef struct			s_vm
{
	char				**argv;
	int					argc;
	
	struct s_file		*file;
}						t_vm;

void					error_exit(t_vm *vm);

void					virtual_machine(t_vm *vm);

void					parse_handler(t_vm *vm);
void					parse_create_file(t_vm *vm);
void					parse_read_file(t_vm *vm);

#endif
