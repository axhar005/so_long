/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:38:52 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 17:52:29 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(void)
{
	t_vec2 origin;

	g()->p_move.hspd = (mlx_is_key_down(g()->mlx, MLX_KEY_D)
			- mlx_is_key_down(g()->mlx, MLX_KEY_A)) * g()->p_move.spd;
	g()->p_move.vspd = (mlx_is_key_down(g()->mlx, MLX_KEY_S)
			- mlx_is_key_down(g()->mlx, MLX_KEY_W)) * g()->p_move.spd;
	origin.x = g()->player.x - SPRITE_SIZE / 2;
	origin.y = g()->player.y - SPRITE_SIZE / 2;

	movement(&origin, &g()->p_move.hspd, g()->p_hitbox, false);
	movement(&origin, &g()->p_move.vspd, g()->p_hitbox, true);

	//update player origin
	g()->player.x = origin.x + SPRITE_SIZE / 2;
	g()->player.y = origin.y + SPRITE_SIZE / 2;
}