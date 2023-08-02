/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:52:05 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 11:26:58 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	tile_collision(t_vec2 pos, int w, int h, int32_t c)
{
	t_vec2	loop;

	loop.x = 0;
	while (loop.x < w)
	{
		loop.y = 0;
		while (loop.y < h)
		{
			if (c == 's')
			{
				if (g()->map[(pos.x + loop.x) / SPRITE_SIZE][(pos.y + loop.y)
					/ SPRITE_SIZE]->solid == true)
					return (true);
			}
			else
			{
				if (g()->map[(pos.x + loop.x) / SPRITE_SIZE][(pos.y + loop.y)
					/ SPRITE_SIZE]->id == c)
					return (true);
			}
			loop.y++;
		}
		loop.x++;
	}
	return (false);
}
