/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:32:06 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/11 20:04:08 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static int			check_next_pos(t_list **list, t_list **stack, t_line *map)
{
	t_piece			*p;

	p = (*list)->content;
	while (p->j < p->w)
	{
		if (!(*((t_block*)(map + p->i)) & (p->tetri >> p->j)))
		{
			*((t_block *)(map + p->i)) ^= (p->tetri >> p->j);
			shift_dupe(p);
			ft_lstadd(stack, ft_lstpop(list));
			p = (*list)->content;
			return (0);
		}
		++(p->j);
	}
	return (1);
}

static int			check_decalance(t_list **list, t_list **stack, t_line *map)
{
	t_piece			*p;
	t_piece			*w;

	if (*stack)
	{
		w = (*stack)->content;
		*((t_block*)(map + w->i)) ^= (w->tetri >> w->j);
		ft_lstadd(list, ft_lstpop(stack));
	}
	p = (*list)->content;
	++(p->j);
	while (p->i < p->h)
	{
		if (check_next_pos(list, stack, map) == 0)
			return (0);
		++(p->i);
		p->j = 0;
	}
	if (*stack == NULL)
		return (0);
	p->i = 0;
	p->j = 0;
	return (1);
}

static int			check_pos(t_list **list, t_list **stack, t_line *map, int i)
{
	t_piece			*p;

	p = (*list)->content;
	while (p->j < p->w)
	{
		if (!(*((t_block *)(map + p->i)) & (p->tetri >> p->j)))
		{
			*((t_block *)(map + p->i)) ^= (p->tetri >> p->j);
			shift_dupe(p);
			ft_lstadd(stack, ft_lstpop(list));
			if (*list)
				p = (*list)->content;
			else
				return (1);
			i = 1;
			break ;
		}
		++(p->j);
	}
	if (i == 1)
	{
		i = 0;
		return (2);
	}
	return (0);
}

static t_list		*solve(t_list *list, t_list *stack, t_line *map)
{
	t_piece			*p;
	int				ret;

	p = list->content;
	while (list)
	{
		while (p->i < p->h)
		{
			if ((ret = check_pos(&list, &stack, map, 0)) == 1)
				return (stack);
			p = list->content;
			if (ret == 2)
				continue ;
			p->j = 0;
			++(p->i);
		}
		p->i = 0;
		while (list != NULL && check_decalance(&list, &stack, map))
			;
		if (stack == NULL)
			return (NULL);
		p = list->content;
	}
	return (list ? stack : NULL);
}

t_list				*fillit_iter(t_list *list)
{
	t_list			*stack;
	t_line			map[16];
	t_list			*tmp;
	int				list_size;
	int				map_size;

	list_size = ft_lstsize(list);
	map_size = 0;
	while (map_size * map_size < 4 * list_size)
		map_size++;
	while (map_size < 13)
	{
		stack = NULL;
		ft_bzero(map, sizeof(map));
		get_shift_range(list, map_size);
		if ((tmp = solve(list, stack, map)) != NULL)
			return (tmp);
		else
			map_size++;
	}
	return (NULL);
}
