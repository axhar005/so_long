/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_tiling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:02:56 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 12:27:50 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int32_t	calculate_auto_tiling(int32_t x, int32_t y, int32_t c)
{
	int32_t	val;

	val = 0;
	if ((x >= 0 && x < R_WIDTH) && (y >= 0 && y < R_HEIGHT))
	{
		if (y - 1 >= 0 && g()->map[x][y - 1]->id == c)
			val += 1;
		if (x + 1 < R_WIDTH && g()->map[x + 1][y]->id == c)
			val += 10;
		if (y + 1 < R_HEIGHT && g()->map[x][y + 1]->id == c)
			val += 100;
		if (x - 1 >= 0 && g()->map[x - 1][y]->id == c)
			val += 1000;
		return (val);
	}
	return (-1);
}

static int32_t	index_auto_tiling(int32_t val)
{
	int32_t	i;
	int		numMappings;

	i = 0;
	int32_t mapping[][2] = {
		{110, 0},
		{1110, 1},
		{1100, 2},
		{111, 3},
		{1111, 4},
		{1101, 5},
		{11, 6},
		{1011, 7},
		{1001, 8},
		{101, 9},
		{1010, 10},
		{0, 11},
		{1, 12},
		{10, 13},
		{100, 14},
		{1000, 15}};
	numMappings = sizeof(mapping) / sizeof(mapping[0]);
	while (i < numMappings)
	{
		if (val == mapping[i][0])
			return (mapping[i][1]);
		i++;
	}
	return (-1);
}

void	auto_tiling(int32_t x, int32_t y, int32_t width, int32_t height)
{
	int32_t i;
	int32_t j;
	int32_t xx;
	int32_t yy;

	i = 0;
	while (i <= width)
	{
		j = 0;
		while (j <= height)
		{
			xx = x + i;
			yy = y + j;
			if ((xx >= 0 && xx < R_WIDTH) && (yy >= 0 && yy < R_HEIGHT))
			{
				if (is_tilable(g()->map[xx][yy]->id))
					g()->map[xx][yy]->tile_index = index_auto_tiling(calculate_auto_tiling(xx,
								yy, g()->map[xx][yy]->id));
			}
			j++;
		}
		i++;
	}
}