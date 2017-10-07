/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 09:32:46 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:45:20 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strcpy(char *dest, const char *src)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char*)src;
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (dest);
}
