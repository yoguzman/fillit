/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:37:10 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:37:11 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if ((mem = (unsigned char*)malloc(size)) == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
