/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:48 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:36:49 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((tmp = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	tmp = f(lst);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (begin);
}
