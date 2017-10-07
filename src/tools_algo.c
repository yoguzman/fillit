/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:43:12 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/11 19:35:06 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void			shift_dupe(t_piece *p)
{
	if (p->dupe)
	{
		p->dupe->i = p->i;
		p->dupe->j = p->j;
	}
}

static t_piece	*find_dupe(t_list *list)
{
	t_piece		*p;
	t_block		tetri;

	p = (t_piece*)list->content;
	tetri = p->tetri;
	list = list->next;
	while (list)
	{
		p = (t_piece*)list->content;
		if (p->tetri == tetri)
			return (p);
		list = list->next;
	}
	return (NULL);
}

void			get_shift_range(t_list *list, int map_size)
{
	t_list		*l;
	t_block		b;
	t_piece		*p;

	l = list;
	while (l)
	{
		p = (t_piece*)l->content;
		p->i = 0;
		p->j = 0;
		p->w = map_size;
		p->h = map_size;
		b = p->tetri;
		while ((b >>= 16) & 0x000000000000ffff)
			p->h--;
		b = p->tetri;
		while ((b <<= 1) & 0x8000800080008000)
			p->w--;
		p->dupe = find_dupe(l);
		l = l->next;
	}
}
