/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:38:55 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:43:54 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*ss;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((res = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	ss = (char*)s;
	p = res;
	while (*ss)
		*p++ = (*f)(*ss++);
	*p = 0;
	return (res);
}
