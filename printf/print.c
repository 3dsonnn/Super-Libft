/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 05:50:39 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:15:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	ft_putchar(int fd, char c, size_t amount, size_t *size)
{
	while (amount)
	{
		write(fd, &c, 1);
		(*size)++;
		amount--;
	}
}

void	ft_putstr(int fd, char *str, int i, size_t *size)
{
	while (str[++i])
		ft_putchar(fd, str[i], 1, size);
}
