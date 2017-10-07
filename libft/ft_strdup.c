/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:38:36 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:45:07 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*t;
	int		len;

	len = ft_strlen(s);
	if ((t = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_memcpy(t, s, len);
	t[len] = 0;
	return (t);
}
