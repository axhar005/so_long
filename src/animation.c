/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:55 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/31 12:53:31 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_player_animation(void)
{
	g()->p_animation.up = ft_split("2,3",',');
	g()->p_animation.down = ft_split("0,1", ',');
	g()->p_animation.left = ft_split("5,4,6,4", ',');
	g()->p_animation.right = ft_split("8,7,9,7", ',');
	g()->p_animation.clock = 0;
	g()->p_animation.speed = 1.8;
	g()->p_animation.index = 0;
	g()->p_animation.loop = 0;
}

void	init_lami_animation(void)
{
	lami()->animation.up = ft_split("0,1,2,3,4,5",',');
	lami()->animation.down = ft_split("0,1,2,3,4,5", ',');
	lami()->animation.left = ft_split("6,7,8,9,10,11", ',');
	lami()->animation.right = ft_split("0,1,2,3,4,5", ',');
	lami()->animation.clock = 0;
	lami()->animation.speed = 1.8;
	lami()->animation.index = 0;
	lami()->animation.loop = 0;
}

void	play_animation(t_animation *animation, char **sheet)
{
	if (animation->old_sheet != sheet)
	{
		animation->loop = 0;
		// animation->clock = 0;
		animation->index = ft_atoi(sheet[0]);
		animation->old_sheet = sheet;
	}
	if (animation->clock >= animation->speed)
	{
		if (animation->loop >= line_count(sheet))
			animation->loop = 0;
		animation->index = ft_atoi(sheet[animation->loop]);
		animation->loop += 1;
		animation->clock = 0;
	}
	animation->sheet = sheet;
	animation->clock += g()->delta_time;
}

/*
(direction, animation_spd)

struct p_animation:
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
