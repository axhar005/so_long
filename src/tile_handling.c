/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:34:56 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 14:16:35 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	replace_tile(t_vec2 pos, int32_t id)
{
	if ((pos.x >= 0 && pos.x < g()->window.r_width) && (pos.y >= 0
			&& pos.y < g()->window.r_height))
	{
		if (g()->tile_type[id].name)
		{
			tile_to_under(g()->map[pos.x][pos.y],
				&g()->map[pos.x][pos.y]->under);
			*g()->map[pos.x][pos.y] = g()->tile_type[id];
		}
		return (true);
	}
	return (false);
}

bool	place_tile(t_vec2 pos, int32_t id)
{
	if ((pos.x >= 0 && pos.x < g()->window.r_width) && (pos.y >= 0
			&& pos.y < g()->window.r_height))
	{
		if (g()->tile_type[id].name)
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
			if ((map.x >= 0 && map.x < g()->window.r_width) && (map.y >= 0
					&& map.y < g()->window.r_height))
				place_tile(map, g()->map[map.x][map.y]->id);
			j++;
		}
		i++;
	}
}
