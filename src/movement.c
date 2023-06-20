/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:28:11 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/06/18 22:24:56 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void movement(t_vec2 pos, int32_t dir, t_hitbox hitbox, int32_t md)
{
    if (dir != 0)
    {
        if (md + dir >= 0 && (md + SPRITE_SIZE)
            + dir <= R_WIDTH * SPRITE_SIZE)
        {
            if (tile_collision((pos.x + hitbox.left) + dir, pos.y
                    + hitbox.top, SPRITE_SIZE - (hitbox.right + hitbox.left),
                     SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
            {
                while (!tile_collision((pos.x + hitbox.left) + sign(dir),
                                        pos.y + hitbox.top,
                                        SPRITE_SIZE - (hitbox.right + hitbox.left),
                                        SPRITE_SIZE - (hitbox.bot + hitbox.top),
                                        's'))
                    md += sign(dir);
                dir = 0;
            }
            md += dir;
        }
        else
        {
            while (md + sign(dir) >= 0 && (md
                    + SPRITE_SIZE) + sign(dir) <= R_WIDTH * SPRITE_SIZE)
                md += sign(dir);
        }
    }
}

void move_colide(t_vec2 *pos, int32_t *dir, t_hitbox hitbox, int32_t *md);
{
    if (tile_collision((pos.x + hitbox.left) + dir, pos.y
        + hitbox.top, SPRITE_SIZE - (hitbox.right + hitbox.left),
        SPRITE_SIZE - (hitbox.bot + hitbox.top), 's'))
    {
        while (!tile_collision((pos.x + hitbox.left) + sign(dir),pos.y + hitbox.top,SPRITE_SIZE 
            - (hitbox.right + hitbox.left),SPRITE_SIZE - (hitbox.bot + hitbox.top),'s'))
            md += sign(dir);
        dir = 0;
    }
}