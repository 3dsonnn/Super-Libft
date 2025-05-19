/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:50:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:10:44 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int	ft_printf(const char *input, ...)
{
	t_printf	ptf;

	if (!input)
		return (-1);
	init_printf(&ptf, input, 1);
	va_start(ptf.args, input);
	read_input(&ptf);
	va_end(ptf.args);
	return (ptf.size);
}
