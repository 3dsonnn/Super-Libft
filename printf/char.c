/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:50:15 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:16:53 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	print_char(t_printf *ptf, char c)
{
	if (ptf->format.width > 1)
	{
		if (ptf->format.minus)
		{
			ft_putchar(ptf->fd, c, 1, &ptf->size);
			ft_putchar(ptf->fd, ' ', ptf->format.width - 1, &ptf->size);
		}
		else
		{
			ft_putchar(ptf->fd, ' ', ptf->format.width - 1, &ptf->size);
			ft_putchar(ptf->fd, c, 1, &ptf->size);
		}
	}
	else
		ft_putchar(ptf->fd, c, 1, &ptf->size);
}
