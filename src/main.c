/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:34:07 by vfour             #+#    #+#             */
/*   Updated: 2016/11/06 20:59:56 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int			main(int argc, char **argv)
{
	t_list	*list;
	t_list	*stack;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetri_list.fillit");
		return (0);
	}
	if ((list = read_tetri(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	if ((stack = fillit_iter(list)))
	{
		print_map(stack);
		ft_lstdel(&stack, &del_tetri_in_list);
	}
	else
	{
		ft_putendl("auie");
		ft_lstdel(&list, &del_tetri_in_list);
	}
	return (0);
}
