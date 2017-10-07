/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:38 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:36:39 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*this;

	if (alst == NULL || *alst == NULL)
		return ;
	prev = *alst;
	while (prev)
	{
		this = prev->next;
		ft_lstdelone(&prev, del);
		prev = this;
	}
	*alst = NULL;
}
