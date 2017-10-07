/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:37:16 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:37:17 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char*)s;
	while (n && *ss != (unsigned char)c)
	{
		++ss;
		--n;
	}
	return (n ? ss : NULL);
}
