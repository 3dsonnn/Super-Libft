/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:14:16 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 14:15:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int	type_check_dot(t_printf *ptf, char *dot, int i, int flag)
{
	if (ft_strchr_count(ptf->format.str, '.') > 1)
		flag++;
	if (ft_strlen(dot) == 2)
		return (0);
	while (dot[++i] && dot[i + 1])
		if (!ft_isdigit(dot[i]))
			flag++;
	if (flag)
	{
		ft_strfree(&ptf->format.str);
		ptf->format.type = '\0';
		return (1);
	}
	return (0);
}

static int	type_check_zero(t_printf *ptf, char *str, char *zero, char *dot)
{
	char	*aux;

	while (zero && *zero == '0')
	{
		aux = zero + ft_strspn(zero, DIGITS);
		if ((!dot && aux == str + ft_strlen(str) - 1) || (dot && *aux == '.'))
			return (0);
		if (ft_strchr(NBR, *(zero + 1)))
		{
			ft_strfree(&ptf->format.str);
			ptf->format.type = '\0';
			return (1);
		}
		zero++;
		zero = ft_strchr(zero, '0');
	}
	return (0);
}

static int	type_check_width(t_printf *ptf, char *width)
{
	char	*tmp;

	tmp = ft_strqbrk(width, DIGITS);
	if (tmp && (ft_strchr(TYPE, *tmp) || *tmp == '.'))
		return (0);
	ft_strfree(&ptf->format.str);
	ptf->format.type = '\0';
	return (1);
}

int	type(t_printf *ptf, char *start, char *end)
{
	ptf->format.end = end;
	ptf->format.str = ft_strndup(start + 1, end - start);
	if (ft_strchr(ptf->format.str, '.') && type_check_dot(ptf,
			ft_strchr(ptf->format.str, '.'), 0, 0))
		return (1);
	if (ft_strchr(ptf->format.str, '0') && type_check_zero(ptf, ptf->format.str,
			ft_strchr(ptf->format.str, '0'), ft_strchr(ptf->format.str, '.')))
		return (1);
	if (ft_strpbrk(ptf->format.str, NBR) && type_check_width(ptf,
			ft_strpbrk(ptf->format.str, NBR)))
		return (1);
	ft_strfree(&ptf->format.str);
	ptf->format.type = *ptf->input;
	return (1);
}
