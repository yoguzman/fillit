/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:49:32 by vfour             #+#    #+#             */
/*   Updated: 2016/07/11 23:21:50 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (*t1 && *t1 == *t2)
	{
		++t1;
		++t2;
	}
	return (*t1 - *t2);
}
