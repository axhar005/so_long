/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:33:00 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/04 20:12:44 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void player_animation_dir(void)
{
    if (mlx_is_key_down(g()->mlx, MLX_KEY_W))
    {
        g()->player_dir = 0;
        play_animation(&g()->player_animation, g()->player_animation.up);
    }
    else if (mlx_is_key_down(g()->mlx, MLX_KEY_S))
    {
        g()->player_dir = 1;
        play_animation(&g()->player_animation, g()->player_animation.down);
    }
    else if (mlx_is_key_down(g()->mlx, MLX_KEY_D))
    {
        g()->player_dir = 2;
        play_animation(&g()->player_animation, g()->player_animation.right);
    }
    else if (mlx_is_key_down(g()->mlx, MLX_KEY_A))
    {
        g()->player_dir = 3;
        play_animation(&g()->player_animation, g()->player_animation.left);
    }
}
