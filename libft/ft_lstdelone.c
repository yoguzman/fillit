/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:41 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:36:42 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		if ((*alst)->content)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			(*alst)->content = NULL;
		}
		ft_memdel((void**)alst);
	}
}
