/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:33:00 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/07 09:52:18 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_animation_dir(void)
{
	if (mlx_is_key_down(g()->mlx, MLX_KEY_W))
	{
		g()->p_direction = 0;
		play_animation(&g()->p_animation, g()->p_animation.up);
	}
	else if (mlx_is_key_down(g()->mlx, MLX_KEY_S))
	{
		g()->p_direction = 1;
		play_animation(&g()->p_animation, g()->p_animation.down);
	}
	else if (mlx_is_key_down(g()->mlx, MLX_KEY_D))
	{
		g()->p_direction = 2;
		play_animation(&g()->p_animation, g()->p_animation.right);
	}
	else if (mlx_is_key_down(g()->mlx, MLX_KEY_A))
	{
		g()->p_direction = 3;
		play_animation(&g()->p_animation, g()->p_animation.left);
	}
}
