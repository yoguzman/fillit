/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:37 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:39:38 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if ((res = (char*)malloc((1 + len) * sizeof(char))) == NULL)
		return (NULL);
	res = ft_memcpy(res, s + start, len);
	res[len] = 0;
	return (res);
}
