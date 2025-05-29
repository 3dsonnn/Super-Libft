/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:49:43 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !*big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < n)
	{
		if (big[i] == *little)
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < n)
			{
				if (little[j + 1] == '\0')
					return ((char *)(&big[i]));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
