/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:45:02 by ffloris           #+#    #+#             */
/*   Updated: 2018/02/26 16:45:25 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstat(t_list *lst, size_t nbr)
{
	if (lst)
	{
		while (nbr > 0 && lst != NULL)
		{
			lst = lst->next;
			nbr--;
		}
		return ((nbr == 0) ? lst : NULL);
	}
	return (NULL);
}
