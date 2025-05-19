/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 07:59:11 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 12:43:29 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static void	init_nbr_aux(t_nbr *nbr, t_integer n)
{
	if (n.i < 0)
	{
		n.i *= -1;
		nbr->neg = 1;
	}
	if (n.i == INT_MIN)
		nbr->str = ft_strdup("2147483648");
	else
		nbr->str = ft_itoa(n.i);
}

int	init_nbr(t_nbr *nbr, t_integer n, char id)
{
	*nbr = (t_nbr){.str = NULL, .tmp = NULL, .aux = NULL, .id = id, .neg = 0,
		.len = 0};
	if (id == 'i')
		init_nbr_aux(nbr, n);
	else if (id == 'u')
		nbr->str = ft_xtoa(n.ui, DIGITS, 10);
	else if (id == 'x')
		nbr->str = ft_xtoa(n.ui, HEXLOW, 16);
	else if (id == 'X')
		nbr->str = ft_xtoa(n.ui, HEXUP, 16);
	else if (id == 'a')
		nbr->str = ft_atoa(n.a, HEXLOW, 16);
	if (!nbr->str)
		return (1);
	nbr->len = ft_strlen(nbr->str);
	return (0);
}

void	init_format(t_printf *ptf)
{
	ptf->format.type = '\0';
	ptf->format.hash = 0;
	ptf->format.zero = 0;
	ptf->format.plus = 0;
	ptf->format.space = 0;
	ptf->format.minus = 0;
	ptf->format.dot = -1;
	ptf->format.width = -1;
	ptf->format.start = ptf->input - 1;
	ptf->format.end = NULL;
}

void	init_printf(t_printf *ptf, const char *input, int fd)
{
	*ptf = (t_printf){.input = (char *)input, .fd = fd, .size = 0,
		.format = (t_format){.str = NULL, .start = NULL, .end = NULL,
		.type = '\0', .hash = 0, .space = 0, .plus = 0, .zero = 0, .minus = 0,
		.dot = -1, .width = -1}};
}
