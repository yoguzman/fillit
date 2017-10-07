/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:24 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:39:25 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ss;
	char	cc;
	char	*pos;

	cc = (char)c;
	ss = (char*)s;
	pos = NULL;
	while (*ss)
	{
		if (*ss == c)
			pos = ss;
		++ss;
	}
	return (*ss == cc ? ss : pos);
}
