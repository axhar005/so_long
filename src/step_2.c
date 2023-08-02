/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:28:41 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 15:09:09 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	step_update(void)
{
	g()->current_time += mlx_get_time();
	g()->playerGrid.x = g()->player.x / SPRITE_SIZE;
	g()->playerGrid.y = g()->player.y / SPRITE_SIZE;
	lami()->grid.x = lami()->pos.x / SPRITE_SIZE;
	lami()->grid.y = lami()->pos.y / SPRITE_SIZE;
	g()->offSet.x = (g()->player.x % SPRITE_SIZE) - SPRITE_SIZE / 2;
	g()->offSet.y = (g()->player.y % SPRITE_SIZE) - SPRITE_SIZE / 2;
	g()->cameraGrid.x = g()->playerGrid.x - g()->window.c_width / 2;
	g()->cameraGrid.y = g()->playerGrid.y - g()->window.c_height / 2;
	g()->mouseGrid.x = g()->cameraGrid.x + ((g()->mouse.x + g()->offSet.x)
		/ SPRITE_SIZE);
	g()->mouseGrid.y = g()->cameraGrid.y + ((g()->mouse.y + g()->offSet.y)
		/ SPRITE_SIZE);
}

void	step_portal(void)
{
	static double	laste_time;
	static t_vec2	exit_pos;
	t_vec2			origin;

	origin.x = g()->player.x - SPRITE_SIZE / 2;
	origin.y = g()->player.y - SPRITE_SIZE / 2;
	if (exit_pos.x == 0 && exit_pos.y == 0)
		exit_pos = char_find_pos_2d(pars()->map, 'E');
	if (g()->cut_tree >= pars()->char_c)
	{
		if (g()->current_time >= laste_time + 100)
		{
			if (g()->map[exit_pos.x][exit_pos.y]->tile_index < 3)
				g()->map[exit_pos.x][exit_pos.y]->tile_index += 1;
			else
				g()->map[exit_pos.x][exit_pos.y]->tile_index = 1;
			laste_time = g()->current_time;
		}
		if (tile_collision((t_vec2){origin.x + g()->p_hitbox.left, (origin.y
					+ g()->p_hitbox.top)}, SPRITE_SIZE - (g()->p_hitbox.right
				+ g()->p_hitbox.left), SPRITE_SIZE - (g()->p_hitbox.bot
				+ g()->p_hitbox.top), PORTAL))
			ft_exit("Good job mate !");
	}
}

void	step_lami(void)
{
	static int32_t	last_h;

	if (g()->current_time >= lami()->time + rand_range(5000, 100000))
	{
		lami()->move.hspd = rand() % 2;
		if (lami()->move.hspd == 0)
			lami()->move.hspd = -1;
		lami()->move.vspd = rand() % 2;
		if (lami()->move.vspd == 0)
			lami()->move.vspd = -1;
		lami()->time = g()->current_time;
	}
	if (lami()->move.hspd != 0)
		last_h = lami()->move.hspd;
	if (lami()->move.hspd == 0 && lami()->move.vspd == 0)
		last_h = 0;
	movement(&lami()->pos, &lami()->move.hspd, lami()->hitbox, false);
	movement(&lami()->pos, &lami()->move.vspd, lami()->hitbox, true);
	if (lami()->move.hspd == 1 || (lami()->move.hspd == 0 && last_h == 1))
		play_animation(&lami()->animation, lami()->animation.right);
	else if (lami()->move.hspd == -1 || (lami()->move.hspd == 0 
			&& last_h == -1))
		play_animation(&lami()->animation, lami()->animation.left);
}
