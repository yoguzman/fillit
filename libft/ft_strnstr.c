/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:20 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:39:22 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*h;
	char	*l;
	char	*hcmp;
	size_t	n;

	h = (char*)big;
	if (*little == 0)
		return (h);
	while (*h && len)
	{
		hcmp = h;
		l = (char*)little;
		n = len;
		while (*hcmp == *l && n)
		{
			if (*(++l) == 0)
				return (h);
			++hcmp;
			--n;
		}
		++h;
		--len;
	}
	return (NULL);
}
