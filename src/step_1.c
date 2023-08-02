/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:27:06 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 13:43:33 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(void)
{
	if (is_key_pressed(MLX_KEY_P) && g()->dev_mod == true)
	{
		g()->mouse_id += 1;
		if (g()->mouse_id > 11)
			g()->mouse_id = 1;
		printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
	}
	else if (is_key_pressed(MLX_KEY_O) && g()->dev_mod == true)
	{
		g()->mouse_id -= 1;
		if (g()->mouse_id < 1)
			g()->mouse_id = 11;
		printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
	}
}

static void	feet_step_count(void)
{
	if (g()->old_PlayerGrid.x != g()->playerGrid.x
		|| g()->old_PlayerGrid.y != g()->playerGrid.y)
	{
		g()->feet_step += 1;
		g()->old_PlayerGrid.x = g()->playerGrid.x;
		g()->old_PlayerGrid.y = g()->playerGrid.y;
		ft_printf("feet : %d\n", g()->feet_step);
	}
}

void	step_game(void)
{
	move();
	feet_step_count();
	player_animation_dir();
	norm1();
	if (is_key_pressed(MLX_KEY_X))
		g()->dev_mod = !g()->dev_mod;
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
