/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:34:56 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/07 09:45:09 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	place_tile(t_vec2 pos, int32_t id)
{
	if ((pos.x >= 0 && pos.x < R_WIDTH) && (pos.y >= 0 && pos.y < R_HEIGHT))
	{
		*g()->map[pos.x][pos.y] = g()->tile_type[id];
		return (true);
	}
	return (false);
}

void	set_map(int32_t x, int32_t y, int32_t width, int32_t height)
{
	int32_t	i;
	int32_t	j;
	t_vec2	map;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			map.x = x + i;
			map.y = y + j;
			if ((map.x >= 0 && map.x < R_WIDTH) && (map.y >= 0
					&& map.y < R_HEIGHT))
				place_tile(map, g()->map[map.x][map.y]->id);
			j++;
		}
		i++;
	}
}