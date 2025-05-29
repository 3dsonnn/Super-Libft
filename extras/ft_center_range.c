/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:34:46 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 21:05:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_point	ft_center_range(t_point big, t_point lil)
{
	return ((t_point){.x = (big.x - lil.x) / 2, .y = (big.y - lil.y) / 2});
}
