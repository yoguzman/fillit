/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:37:03 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:37:04 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstreverse(t_list **lst)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = (*lst);
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}
