/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:10:24 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:17:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static void	select_printer(t_printf *ptf)
{
	if (!ptf->format.type)
		print_no_type(ptf);
	if (ptf->format.type == 'c')
		print_char(ptf, (char)va_arg(ptf->args, int));
	if (ptf->format.type == 's')
		print_str(ptf, (char *)va_arg(ptf->args, char *), -1, 0);
	if (ptf->format.type == 'p')
		print_addr(ptf, (void *)va_arg(ptf->args, void *));
	if (ptf->format.type == 'd' || ptf->format.type == 'i')
		print_int(ptf, (int)va_arg(ptf->args, int));
	if (ptf->format.type == 'u')
		print_uint(ptf, (unsigned int)va_arg(ptf->args, unsigned int));
	if (ptf->format.type == 'x')
		print_hex(ptf, (unsigned int)va_arg(ptf->args, unsigned int), 'x');
	if (ptf->format.type == 'X')
		print_hex(ptf, (unsigned int)va_arg(ptf->args, unsigned int), 'X');
	if (ptf->format.type == '%')
		ft_putchar(ptf->fd, '%', 1, &ptf->size);
	ptf->input = ptf->format.end + 1;
}

void	read_input(t_printf *ptf)
{
	while (*ptf->input)
	{
		if (*ptf->input == '%')
		{
			ptf->input++;
			if (!*ptf->input)
				break ;
			init_format(ptf);
			parse_format(ptf);
			select_printer(ptf);
			continue ;
		}
		ft_putchar(ptf->fd, *ptf->input, 1, &ptf->size);
		ptf->input++;
	}
}
