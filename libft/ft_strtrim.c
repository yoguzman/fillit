/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:48 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:43:19 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*ss;
	char	*end;
	size_t	size;
	char	*res;

	if (s == NULL)
		return (NULL);
	ss = (char*)s;
	end = ss + ft_strlen(s) - 1;
	while (*ss == ' ' || *ss == '\n' || *ss == '\t')
		++ss;
	while (end >= ss && (*end == ' ' || *end == '\n' || *end == '\t'))
		--end;
	size = end - ss + 2;
	if ((res = (char *)malloc(size * sizeof(char))) == NULL)
		return (NULL);
	if (size > 1)
		res = ft_memcpy(res, ss, size);
	res[size - 1] = 0;
	return (res);
}
