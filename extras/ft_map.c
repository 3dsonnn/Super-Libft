/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:37:57 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 17:38:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_map(int old_value, int old_limits[2], int new_limits[2])
{
	double	old_range;
	double	new_range;
	int		old_pos_range;

	new_range = new_limits[1] - new_limits[0];
	old_pos_range = old_value - old_limits[0];
	old_range = old_limits[1] - old_limits[0];
	if (!old_range)
		return (new_limits[0]);
	return ((int)(((new_range * old_pos_range) / old_range) + new_limits[0]));
}
