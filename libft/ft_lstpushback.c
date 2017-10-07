/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:59 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:37:01 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new && lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
