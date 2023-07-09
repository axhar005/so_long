/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:52:05 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/08 17:52:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	tile_collision(int x, int y, int w, int h, int32_t c)
{
	t_vec2 loop;

	loop.x = 0;
	while (loop.x < w)
	{
		loop.y = 0;
		while (loop.y < h)
		{
			if (c == 's')
			{
				if (g()->map[(x + loop.x) / SPRITE_SIZE][(y + loop.y)
					/ SPRITE_SIZE]->solid == true)
					return (true);
			}
			else
			{
				if (g()->map[(x + loop.x) / SPRITE_SIZE][(y + loop.y)
					/ SPRITE_SIZE]->id == c)
					return (true);
			}
			loop.y++;
		}
		loop.x++;
	}
	return (false);
}