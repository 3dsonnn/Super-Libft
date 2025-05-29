/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:16:51 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_char(char *str, char dst, char src)
{
	int	i;

	i = -1;
	if (!str || !*str || src == dst)
		return ;
	while (str[++i])
		if (str[i] == dst)
			str[i] = src;
}
