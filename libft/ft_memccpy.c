/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:37:13 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:37:14 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned char			*s;
	register unsigned char	cc;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	cc = (unsigned char)c;
	while (n && ((*d++ = *s++) != cc))
		--n;
	return (n ? d : NULL);
}
