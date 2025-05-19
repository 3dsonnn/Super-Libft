/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:48 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:33:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_realloc(char **matrix, char **tmp, int old_size, int new_size)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (new_size + 1));
	while (i < old_size)
	{
		res[i] = matrix[i];
		i++;
	}
	while (i < new_size)
	{
		res[i] = tmp[j];
		i++;
		j++;
	}
	res[i] = NULL;
	free(matrix);
	return (res);
}
