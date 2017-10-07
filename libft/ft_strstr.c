/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 09:48:42 by vfour             #+#    #+#             */
/*   Updated: 2016/07/11 21:51:42 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	char	*hcmp;

	h = (char*)haystack;
	if (*needle == 0)
		return (h);
	while (*h)
	{
		hcmp = h;
		n = (char*)needle;
		while (*hcmp++ == *n++)
			if (*n == 0)
				return (h);
		++h;
	}
	return (NULL);
}
