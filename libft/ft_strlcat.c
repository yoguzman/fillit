/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:34:10 by vfour             #+#    #+#             */
/*   Updated: 2016/07/12 15:58:58 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > size)
		return (size + len_src);
	d = dst + len_dst;
	s = (char*)src;
	size = size - len_dst;
	while (*s && --size)
		*d++ = *s++;
	*d = 0;
	return (len_dst + len_src);
}
