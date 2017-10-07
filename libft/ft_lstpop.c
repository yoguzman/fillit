/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:55 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:36:57 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpop(t_list **alst)
{
	t_list	*ret;

	if (alst == NULL)
		return (NULL);
	ret = *alst;
	*alst = (*alst)->next;
	ret->next = NULL;
	return (ret);
}
