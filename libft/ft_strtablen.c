/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:44 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:39:45 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strtablen(char **tab)
{
	int		size;

	if (tab == NULL)
		return (0);
	size = 0;
	while (tab[size])
		++size;
	return (size);
}
