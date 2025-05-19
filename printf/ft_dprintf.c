/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:05:07 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:10:36 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int	ft_dprintf(int fd, const char *input, ...)
{
	t_printf	ptf;

	if (!input || fd < 0)
		return (-1);
	init_printf(&ptf, input, fd);
	va_start(ptf.args, input);
	read_input(&ptf);
	va_end(ptf.args);
	return (ptf.size);
}
