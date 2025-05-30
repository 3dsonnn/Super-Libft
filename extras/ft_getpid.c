/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:49:56 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getpid(void)
{
	char	buffer[256];
	int		ptr[4];

	ft_bzero(ptr, sizeof(ptr));
	ft_bzero(buffer, sizeof(buffer));
	*ptr = open("/proc/self/stat", O_RDONLY);
	if (*ptr < 0)
		return (-1);
	*(ptr + 1) = read(*ptr, buffer, sizeof(buffer) - 1);
	close(*ptr);
	if (*(ptr + 1) <= 0)
		return (-1);
	*(ptr + 2) = ft_atoi(buffer);
	if (*(ptr + 2) <= 0)
		return (-1);
	return (*(ptr + 2));
}
