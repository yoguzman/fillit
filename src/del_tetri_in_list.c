/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tetri_in_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:34:05 by vfour             #+#    #+#             */
/*   Updated: 2016/11/04 20:34:17 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	del_tetri_in_list(void *piece, size_t size)
{
	(void)size;
	free(piece);
	piece = NULL;
}
