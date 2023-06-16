/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:55 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/06/16 17:38:03 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void init_player_animation(t_game *game)
{
    game->player_animation.up = ft_split("2,3", ',');
	game->player_animation.down = ft_split("0,1", ',');
	game->player_animation.left = ft_split("4,5,4,6", ',');
	game->player_animation.right = ft_split("7,8,7,9", ',');
    game->player_animation.clock = 0;
    game->player_animation.speed = 1.8;
    game->player_animation.index = 0;
    game->player_animation.loop = 0;
}

void play_animation(t_game *game, t_animation *animation, char **direction)
{
    if (animation->clock >= animation->speed)
    {
		if (animation->loop >= ft_strnum(direction))
			animation->loop = 0;
        animation->index = ft_atoi(direction[animation->loop]);
		animation->loop += 1;
    	animation->clock = 0;
    }
	animation->clock += game->delta_time;
}

/*
(direction, animation_spd)

struct player_animation:
    index = 0;
    up = [0, 1];
    down = [2, 3];
    right = [4, 5, 4, 6];
    left = [7, 8, 7, 9];


while:
    indwx = 0;
    if (>= array_length) {
        index = 0;
    } else {
        index++;
    }
*/
