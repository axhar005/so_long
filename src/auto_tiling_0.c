/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_tiling_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:02:56 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/10 09:32:35 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//calculate auto tiling
static int32_t	ct(int32_t x, int32_t y, int32_t c)
{
	int32_t	val;

	val = 0;
	if ((x >= 0 && x < g()->window.r_width) && (y >= 0
			&& y < g()->window.r_height))
	{
		if ((y - 1 >= 0 && g()->map[x][y - 1]->id == c) || (y - 1 >= 0
				&& g()->map[x][y - 1]->under.id == c))
			val += 1;
		if ((x + 1 < g()->window.r_width && g()->map[x + 1][y]->id == c) || (x
				+ 1 < g()->window.r_width && g()->map[x + 1][y]->under.id == c))
			val += 10;
		if ((y + 1 < g()->window.r_height && g()->map[x][y + 1]->id == c) || (y
				+ 1 < g()->window.r_height && g()->map[x][y
				+ 1]->under.id == c))
			val += 100;
		if ((x - 1 >= 0 && g()->map[x - 1][y]->id == c) || (x - 1 >= 0
				&& g()->map[x - 1][y]->under.id == c))
			val += 1000;
		return (val);
	}
	return (-1);
}

static void	array_set(int32_t *mapping)
{
	mapping[0] = 110;
	mapping[1] = 1110;
	mapping[2] = 1100;
	mapping[3] = 111;
	mapping[4] = 1111;
	mapping[5] = 1101;
	mapping[6] = 11;
	mapping[7] = 1011;
	mapping[8] = 1001;
	mapping[9] = 101;
	mapping[10] = 1010;
	mapping[11] = 0;
	mapping[12] = 1;
	mapping[13] = 10;
	mapping[14] = 100;
	mapping[15] = 1000;
}

//index auto tiling
static int32_t	it(int32_t val)
{
	int32_t	i;
	int32_t	mapping[16];
	int		nummappings;

	i = 0;
	array_set(mapping);
	nummappings = sizeof(mapping) / sizeof(mapping[0]);
	while (i < nummappings)
	{
		if (val == mapping[i])
			return (i);
		i++;
	}
	return (-1);
}

static void	norm1(t_pos2 c, t_tile ***m)
{
	if (is_tilable(g()->map[c.pos2.x][c.pos2.y]->id))
		m[c.pos2.x][c.pos2.y]->tile_index = \
			it(ct(c.pos2.x, c.pos2.y, m[c.pos2.x][c.pos2.y]->id));
	else if (is_tilable(m[c.pos2.x][c.pos2.y]->under.id))
		m[c.pos2.x][c.pos2.y]->under.tile_index = \
			it(ct(c.pos2.x, c.pos2.y, m[c.pos2.x][c.pos2.y]->under.id));
}

void	auto_tiling(t_vec2 pos, int32_t width, int32_t height)
{
	t_pos2	c;
	t_tile	***m;

	c.pos1.x = 0;
	m = g()->map;
	while (c.pos1.x <= width)
	{
		c.pos1.y = 0;
		while (c.pos1.y <= height)
		{
			c.pos2.x = pos.x + c.pos1.x;
			c.pos2.y = pos.y + c.pos1.y;
			if ((c.pos2.x >= 0 && c.pos2.x < g()->window.r_width)
				&& (c.pos2.y >= 0 && c.pos2.y < g()->window.r_height))
			{
				norm1(c, m);
			}
			c.pos1.y++;
		}
		c.pos1.x++;
	}
}
