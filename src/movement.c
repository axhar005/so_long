/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:28:11 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/06/23 21:39:16 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	movement(t_vec2 *pos, int32_t *dir, t_hitbox hitbox, bool is_vertical)
{
	int32_t *md;

	if (is_vertical == true)
		md = &pos->y;
	else
		md = &pos->x;	
	if (*dir != 0)
	{
		if (*md + *dir >= 0 && (*md + SPRITE_SIZE) + *dir <= R_WIDTH * SPRITE_SIZE)
		{
			if (is_vertical)
				move_colide_vertical(pos, dir, hitbox);
			else
				move_colide_horizontal(pos, dir, hitbox);
				
			*md += *dir;
		}
		else
		{
			while (*md + sign(*dir) >= 0 && (*md + SPRITE_SIZE)
				+ sign(*dir) <= R_WIDTH * SPRITE_SIZE)
				*md += sign(*dir);
		}
	}
}

void	move_colide_vertical(t_vec2 *pos, int32_t *dir, t_hitbox hitbox)
{
		if (tile_collision(pos->x + hitbox.left, (pos->y + hitbox.top)
			+ *dir, SPRITE_SIZE - (hitbox.right + hitbox.left), SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
		{
			while (!tile_collision(pos->x + hitbox.left, (pos->y
						+ hitbox.top) + sign(*dir), SPRITE_SIZE - (hitbox.right + hitbox.left),
					SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
				pos->y += sign(*dir);
			*dir = 0;
		}
}

void	move_colide_horizontal(t_vec2 *pos, int32_t *dir, t_hitbox hitbox)
{
	if (tile_collision(pos->x + hitbox.left + *dir, (pos->y + hitbox.top), 
		SPRITE_SIZE - (hitbox.right + hitbox.left), SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
	{
		while (!tile_collision(pos->x + hitbox.left + sign(*dir), (pos->y
					+ hitbox.top), SPRITE_SIZE - (hitbox.right + hitbox.left),
				SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
			pos->x += sign(*dir);
		*dir = 0;
	}
}