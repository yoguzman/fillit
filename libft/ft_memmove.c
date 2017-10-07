/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:37:40 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:45:29 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
