/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:39:32 by vfour             #+#    #+#             */
/*   Updated: 2016/11/03 13:39:32 by vfour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c, int count)
{
	if (*s == 0)
		return (count);
	if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
		return (ft_count_words(s + 1, c, count + 1));
	return (ft_count_words(s + 1, c, count));
}

static char	*ft_get_next_word(char const *s, char c, int *start)
{
	char	*t;
	int		end;
	int		b;

	t = (char *)s;
	end = 0;
	b = *start;
	while (t[b] && t[b] == c)
		++b;
	if (t[b] == 0)
		return (NULL);
	end = b;
	while (t[end] && t[end] != c)
		++end;
	*start = end + 1;
	return (ft_strsub(s, b, end - b));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		num_words;
	int		i;
	int		word_start;

	if (s == NULL)
		return (NULL);
	num_words = ft_count_words(s, c, 0);
	if ((tab = (char**)malloc((num_words + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	word_start = 0;
	while (i < num_words)
	{
		tab[i] = ft_get_next_word(s, c, &word_start);
		if (tab[i] == NULL)
		{
			ft_strtabdel(tab);
			return (NULL);
		}
		++i;
	}
	tab[num_words] = NULL;
	return (tab);
}
