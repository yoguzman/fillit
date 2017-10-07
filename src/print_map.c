/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:34:12 by vfour             #+#    #+#             */
/*   Updated: 2016/11/04 21:55:13 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "fillit.h"

static char		*put_tetri_in_str(char *str, t_piece *piece, int size, int k)
{
	int			i;
	int			l;
	char		c;
	t_block		mask;
	t_block		tetri;

	c = 'A' + k;
	tetri = piece->tetri >> piece->j;
	l = piece->i;
	while (tetri & 0x000000000000ffff)
	{
		mask = 1 << 15;
		i = 0;
		while (i < size)
		{
			if (tetri & mask)
				str[l * (size + 1) + i] = c;
			mask >>= 1;
			++i;
		}
		str[l * (size + 1) + i] = '\n';
		tetri >>= 16;
		++l;
	}
	return (str);
}

void			put_endl(char *str, int size)
{
	int			i;

	i = size;
	while (i < size * (size + 1))
	{
		str[i] = '\n';
		i += (size + 1);
	}
}

void			print_map(t_list *list)
{
	int			size;
	int			list_size;
	char		*str;
	t_piece		*p;
	t_block		tetri;

	p = (t_piece*)(list->content);
	size = p->h;
	tetri = p->tetri;
	while ((tetri >>= 16) & 0x000000000000ffff)
		++size;
	list_size = ft_lstsize(list);
	if ((str = (char*)malloc(sizeof(char) * (size * (size + 1) + 1))) == NULL)
		return ;
	str = ft_memset(str, '.', size * (size + 1));
	put_endl(str, size);
	while (list)
	{
		str = put_tetri_in_str(str, list->content, size, --list_size);
		list = list->next;
	}
	str[size * (size + 1)] = 0;
	ft_putstr(str);
	free(str);
}
