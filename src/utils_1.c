/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:51:55 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 17:05:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	sign(int nb)
{
	return ((nb > 0) - (nb < 0));
}

bool	is_even(int nb)
{
	if (nb % 2 == 0)
		return (true);
	return (false);
}

bool	is_tilable(int32_t id)
{
	if (id == GRASS || id == HILL || id == WATER || id == SAND 
		|| id == DEEP_DIRT || id == WOOD_WALL || id == STONE_WALL)
		return (true);
	return (false);
}

int32_t	point_distance(t_vec2 bow, t_vec2 target)
{
	int32_t cal1;
	int32_t cal2;
	int32_t res;

	cal1 = (bow.x - target.x);
	cal2 = (bow.y - target.y);
	if (cal1 < 0)
		cal1 *= -1;
	if (cal2 < 0)
		cal2 *= -1;
	res = cal1 + cal2;
	if (res < 0)
		res *= -1;
	return (res);
}