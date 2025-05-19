/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:23:17 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:13:47 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	int_reverse_fill(char *dst, char *src)
{
	int	i;
	int	j;

	if (!dst || !src)
		return ;
	*dst = *src;
	++src;
	i = ft_strlen(src);
	j = ft_strlen(dst);
	while (--i > -1)
		dst[--j] = src[i];
}

void	hex_reverse_fill(char *dst, char *src)
{
	int	i;
	int	j;

	if (!dst || !src)
		return ;
	*dst = *src;
	*(dst + 1) = *(src + 1);
	src += 2;
	i = ft_strlen(src);
	j = ft_strlen(dst);
	while (--i > -1)
		dst[--j] = src[i];
}
