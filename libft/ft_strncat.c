/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:34:10 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 23:29:50 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;
	size_t	l;

	d = dest + ft_strlen(dest);
	l = ft_strlen(src);
	l = l < n ? l : n;
	ft_memcpy(d, src, l);
	*(d + l) = 0;
	return (dest);
}
