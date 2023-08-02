/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:38:52 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 13:27:13 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(void)
{
	t_vec2	origin;
	t_game	*ga;

	ga = g();
	ga->p_move.hspd = (mlx_is_key_down(g()->mlx, MLX_KEY_D) \
		- mlx_is_key_down(g()->mlx, MLX_KEY_A)) * g()->p_move.spd;
	ga->p_move.vspd = (mlx_is_key_down(g()->mlx, MLX_KEY_S) \
		- mlx_is_key_down(g()->mlx, MLX_KEY_W)) * g()->p_move.spd;
	origin.x = ga->player.x - SPRITE_SIZE / 2;
	origin.y = ga->player.y - SPRITE_SIZE / 2;
	movement(&origin, &g()->p_move.hspd, g()->p_hitbox, false);
	movement(&origin, &g()->p_move.vspd, g()->p_hitbox, true);
	g()->player.x = origin.x + SPRITE_SIZE / 2;
	g()->player.y = origin.y + SPRITE_SIZE / 2;
}
