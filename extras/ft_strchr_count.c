/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:22:45 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:33:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strchr_count(char *str, int c)
{
	int	res;

	res = 0;
	if (!str || c == '\0')
		return (res);
	while (*str)
	{
		if (*str == c)
			res++;
		str++;
	}
	return (res);
}
