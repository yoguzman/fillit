/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:33:39 by vfour             #+#    #+#             */
/*   Updated: 2016/11/04 21:39:14 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include "fillit.h"

static int	check_contiguity(char **piece)
{
	int		i;
	int		j;
	int		p;

	i = -1;
	p = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (piece[i][j] != FILLED)
				continue ;
			if (i > 0 && piece[i - 1][j] == FILLED)
				++p;
			if (i < 3 && piece[i + 1][j] == FILLED)
				++p;
			if (j > 0 && piece[i][j - 1] == FILLED)
				++p;
			if (j < 3 && piece[i][j + 1] == FILLED)
				++p;
		}
	}
	return (p > 4 ? 1 : 0);
}

static int	count_char(char **s, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == c)
				count++;
			++j;
		}
		++i;
	}
	return (count);
}

int			check_tetri(char **piece)
{
	int		len;
	int		i;

	len = 0;
	if (piece == NULL)
		return (0);
	while (piece[len])
	{
		if (ft_strlen(piece[len]) != 4)
			return (0);
		i = 0;
		while (i < 4)
		{
			if (!(piece[len][i] == EMPTY || piece[len][i] == FILLED))
				return (0);
			++i;
		}
		++len;
	}
	if (len != 4)
		return (0);
	if (!check_contiguity(piece) || count_char(piece, FILLED) != 4)
		return (0);
	return (1);
}
