/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:28:11 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/04 22:09:38 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_colide_vertical(t_vec2 *pos, int32_t *dir, t_hitbox hitbox)
{
	if (tile_collision(pos->x + hitbox.left, (pos->y + hitbox.top) + *dir,
			SPRITE_SIZE - (hitbox.right + hitbox.left), SPRITE_SIZE
			- (hitbox.bot + hitbox.top), 's'))
	{
		while (!tile_collision(pos->x + hitbox.left, (pos->y + hitbox.top)
				+ sign(*dir), SPRITE_SIZE - (hitbox.right + hitbox.left),
				SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
			pos->y += sign(*dir);
		*dir = 0;
	}
}

static void	move_colide_horizontal(t_vec2 *pos, int32_t *dir, t_hitbox hitbox)
{
	if (tile_collision(pos->x + hitbox.left + *dir, (pos->y + hitbox.top),
			SPRITE_SIZE - (hitbox.right + hitbox.left), SPRITE_SIZE
			- (hitbox.bot + hitbox.top), 's'))
	{
		while (!tile_collision(pos->x + hitbox.left + sign(*dir), (pos->y
					+ hitbox.top), SPRITE_SIZE - (hitbox.right + hitbox.left),
				SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
			pos->x += sign(*dir);
		*dir = 0;
	}
}

static void norm1(t_vec2 *pos, int32_t *dir, t_hitbox hitbox, bool is_vertical)
{
	if (is_vertical)
				move_colide_vertical(pos, dir, hitbox);
			else
				move_colide_horizontal(pos, dir, hitbox);
}

static void norm2(int32_t *dir, int32_t *md, int32_t size)
{
	while (*md + sign(*dir) >= 0 && (*md + SPRITE_SIZE)
				+ sign(*dir) <= size * SPRITE_SIZE)
				*md += sign(*dir);
}

void	movement(t_vec2 *pos, int32_t *dir, t_hitbox hitbox, bool is_vertical)
{
	int32_t	*md;
	int32_t size;

	if (is_vertical == true)
	{
		md = &pos->y;
		size = R_HEIGHT;	
	}
	else
	{
		md = &pos->x;
		size = R_WIDTH;
	}
	if (*dir != 0)
	{
		if (*md + *dir >= 0 && (*md + SPRITE_SIZE) + *dir <= size
			* SPRITE_SIZE)
		{
			norm1(pos, dir, hitbox, is_vertical);
			*md += *dir;
		}
		else
			norm2(dir, md, size);
	}
}