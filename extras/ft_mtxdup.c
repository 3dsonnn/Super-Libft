/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:59:41 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mtxdup(char **matrix)
{
	char	**tmp;
	int		i;
	int		len;

	if (!matrix || !(*matrix))
		return (NULL);
	i = -1;
	len = ft_mtxlen(matrix);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (++i < len)
	{
		tmp[i] = ft_strdup(matrix[i]);
		if (!tmp[i])
		{
			ft_mtxfree(&tmp);
			return (NULL);
		}
	}
	tmp[i] = NULL;
	return (tmp);
}
