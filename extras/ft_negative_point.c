/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:18:41 by efinda            #+#    #+#             */
/*   Updated: 2025/05/25 18:31:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

inline int	ft_negative_point(t_point point, int flag)
{
	if (!flag && (point.x < 0 || point.y < 0))
		return (1);
	else if (flag == 1 && point.x < 0)
		return (1);
    else if (flag == 2 && point.y < 0)
		return (1);
	return (0);
}
