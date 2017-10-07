/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:15:25 by vfour             #+#    #+#             */
/*   Updated: 2016/11/11 15:47:48 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define PIECE_SIZE 20
# define EMPTY '.'
# define FILLED '#'

typedef unsigned short		t_line;
typedef unsigned long long	t_block;

typedef struct				s_piece
{
	t_block					tetri;
	char					w;
	char					h;
	char					i;
	char					j;
	struct s_piece			*dupe;
}							t_piece;

t_list						*read_tetri(char *filename);
int							check_tetri(char **piece);
void						del_tetri_in_list(void *piece, size_t size);
t_list						*fillit_rec(t_list *list);
t_list						*fillit_iter(t_list *list);
void						print_map(t_list *list);
void						shift_dupe(t_piece *p);
void						get_shift_range(t_list *list, int map_size);

#endif
