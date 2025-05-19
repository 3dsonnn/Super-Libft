/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:48:25 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:16:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

void	print_no_type(t_printf *ptf)
{
	while (ptf->format.start)
	{
		ft_putchar(ptf->fd, *ptf->format.start, 1, &ptf->size);
		++ptf->format.start;
		if (ptf->format.start == ptf->format.end)
		{
			ft_putchar(ptf->fd, *ptf->format.start, 1, &ptf->size);
			break ;
		}
	}
}
