/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:42:31 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:33:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcspn(char *s, char *reject)
{
	int	i;
	int	j;

	i = -1;
	if (!s || !reject)
		return (-1);
	while (s[++i])
	{
		j = -1;
		while (reject[++j])
			if (s[i] == reject[j])
				return (i);
	}
	return (i);
}
