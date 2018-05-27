/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:17:04 by ffloris           #+#    #+#             */
/*   Updated: 2018/05/16 11:17:25 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	unsigned long	nbr;
	int				neg;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
		neg = 0;
		if (*str == '+')
			str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg) ? -(long)nbr : (long)nbr;
}
