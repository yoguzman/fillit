/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:04 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:36:06 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	int				res;
	unsigned int	pos;

	res = 0;
	pos = 1;
	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\r'
			|| *nptr == '\v' || *nptr == '\f' || *nptr == ' ')
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			pos = 0;
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return (pos ? res : -res);
}
