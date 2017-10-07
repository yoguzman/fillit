/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:34:14 by vfour             #+#    #+#             */
/*   Updated: 2016/11/04 23:08:06 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "fillit.h"

static t_piece	*tabtopiece(char **a)
{
	int			i;
	int			j;
	t_piece		*p;
	t_line		*line;

	if ((p = (t_piece*)ft_memalloc(sizeof(t_piece))) == NULL)
		return (NULL);
	i = 0;
	line = (t_line*)(&(p->tetri));
	while (i < 4)
	{
		j = 0;
		line[i] = 0;
		while (j < 4)
		{
			line[i] = (line[i] << 1) + (a[i][j] == FILLED);
			++j;
		}
		line[i] = line[i] << 12;
		++i;
	}
	return (p);
}

static void		free_tab_and_res(char **tab, char *res)
{
	int			i;

	i = 0;
	if (tab == NULL || *tab == NULL || res == NULL)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	free(res);
}

static void		init_tetri_pos(t_piece *p)
{
	while (!(p->tetri & 0x000000000000ffff))
		p->tetri >>= 16;
	while (!(p->tetri & 0x8000800080008000))
		p->tetri <<= 1;
}

static int		get_next_tetri(int fd, t_piece **piece)
{
	int			n;
	char		*res;
	char		**str_piece;

	if ((res = (char*)malloc(sizeof(char) * (PIECE_SIZE + 2))) == NULL)
		return (-1);
	if ((n = read(fd, res, PIECE_SIZE + 1)) >= PIECE_SIZE)
	{
		res[n] = 0;
		if (!check_tetri(str_piece = ft_strsplit(res, '\n')))
		{
			free(res);
			return (-1);
		}
		*piece = tabtopiece(str_piece);
		free_tab_and_res(str_piece, res);
		if (*piece == NULL)
			return (-1);
		init_tetri_pos(*piece);
		return (n == PIECE_SIZE ? 0 : 1);
	}
	free(res);
	return (-1);
}

t_list			*read_tetri(char *filename)
{
	int			fd;
	int			n;
	t_piece		*piece;
	t_list		*list;

	piece = NULL;
	list = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while ((n = get_next_tetri(fd, &piece)) != -1)
	{
		ft_lstpushback(&list, ft_lstnew(piece, sizeof(t_piece)));
		free(piece);
		if (n == 0)
			break ;
	}
	close(fd);
	if (n == -1)
	{
		ft_lstdel(&list, &del_tetri_in_list);
		return (NULL);
	}
	if (list && list->content_size == 0)
		return (NULL);
	return (list);
}
