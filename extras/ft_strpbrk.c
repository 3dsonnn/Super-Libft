/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:56:32 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:33:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strpbrk(char *str, char *accept)
{
	if (!str || !accept)
		return (NULL);
	while (*str)
	{
		if (ft_strchr(accept, *str))
			return (str);
		str++;
	}
	return (NULL);
}
