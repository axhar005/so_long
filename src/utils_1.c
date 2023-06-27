/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:51:55 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/27 13:26:45 by oboucher         ###   ########.fr       */
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
	if (id == 0 || id == 1 || id == 3 || id == 4 || id == 5)
		return (true);
	return (false);
}

int32_t point_distance(t_vec2 bow, t_vec2 target)
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