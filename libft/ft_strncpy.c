/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 09:40:52 by vfour             #+#    #+#             */
/*   Updated: 2016/07/11 09:48:03 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char*)src;
	while (n-- && *s)
		*d++ = *s++;
	ft_memset(d, 0, n + 1);
	return (dest);
}
