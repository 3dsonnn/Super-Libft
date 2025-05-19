/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:03:56 by efinda            #+#    #+#             */
/*   Updated: 2025/05/16 16:40:21 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_fill_mtx(char ***mtx, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			(*mtx)[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (!(*mtx)[k])
				return (1);
			ft_strlcpy((*mtx)[k], &s[j], (i - j + 1));
			k++;
		}
	}
	(*mtx)[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**res;

	if (!s)
		return (NULL);
	wc = ft_word_count((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	if (ft_fill_mtx(&res, s, c))
	{
		ft_mtxfree(&res);
		return (NULL);
	}
	return (res);
}
