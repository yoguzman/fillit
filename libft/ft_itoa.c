/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:36:29 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:45:51 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_num_char(int n, int count)
{
	if (n < 10 && n > -10)
		return ((n < 0) ? count + 1 : count);
	return (ft_num_char(n / 10, count + 1));
}

char		*ft_itoa(int n)
{
	int		k;
	int		nsave;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	k = ft_num_char(n, 1);
	if ((res = (char *)malloc(sizeof(char) * (k + 1))) == NULL)
		return (NULL);
	nsave = n;
	res[k] = 0;
	if (n < 0)
		n = -n;
	while (k)
	{
		res[--k] = n % 10 + '0';
		n /= 10;
	}
	if (nsave < 0)
		res[0] = '-';
	return (res);
}
