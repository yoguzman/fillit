/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:38:58 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:44:12 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((mapped = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = (*f)(i, s[i]);
		i++;
	}
	mapped[i] = 0;
	return (mapped);
}
