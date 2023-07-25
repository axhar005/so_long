/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:27:06 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:19 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(void)
{
	if (is_key_pressed(MLX_KEY_P))
	{
		g()->mouse_id += 1;
		if (g()->mouse_id > 11)
			g()->mouse_id = 1;
		printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
	}
}

void	step_game(void)
{
	move();
	player_animation_dir();
	norm1();
	if (is_key_pressed(MLX_KEY_O))
	{
		g()->mouse_id -= 1;
		if (g()->mouse_id < 1)
			g()->mouse_id = 11;
		printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
	}
	if (is_key_pressed(MLX_KEY_M))
		print_2d_map_array(g()->map, g()->window.r_width, g()->window.r_height);
	if (is_key_pressed(MLX_KEY_ESCAPE))
	{
		del_img(&g()->old_img);
		del_img(&g()->img);
		init_menu();
		g()->state = PAUSE;
	}
}