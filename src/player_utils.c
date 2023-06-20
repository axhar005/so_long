/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:33:00 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/20 13:37:27 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void player_animation_dir(t_game *game)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
    {
        game->player_dir = 0;
        play_animation(game, &game->player_animation, game->player_animation.up);
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
    {
        game->player_dir = 1;
        play_animation(game, &game->player_animation, game->player_animation.down);
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
    {
        game->player_dir = 2;
        play_animation(game, &game->player_animation, game->player_animation.right);
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
    {
        game->player_dir = 3;
        play_animation(game, &game->player_animation, game->player_animation.left);
    }
}
