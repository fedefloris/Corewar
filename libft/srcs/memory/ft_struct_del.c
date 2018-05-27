/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:13:11 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/30 14:29:23 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_struct_del(void *el, size_t el_size)
{
	if (!el)
		return ;
	free(el);
	(void)el_size;
}
