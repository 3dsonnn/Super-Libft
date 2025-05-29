/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:08:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtxfree(char ***matrix)
{
	int	i;

	i = -1;
	if (!matrix || !(*matrix) || !(*matrix)[0])
		return ;
	while ((*matrix)[++i])
	{
		if ((*matrix)[i])
			free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}
