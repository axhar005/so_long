/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:23:26 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/31 17:28:09 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_all(void)
{
	init_window();
	init_all_tiles();
	init_player_animation();
	init_lami_animation();
	init_val();
}

void	init_window(void)
{
	g()->window.width = 1216;
	g()->window.height = 704;
	g()->window.c_width = g()->window.width / SPRITE_SIZE;
	g()->window.c_height = g()->window.height / SPRITE_SIZE;
	g()->window.r_width = pars()->width;
	g()->window.r_height = pars()->height;
}

void	init_val(void)
{
	g()->playerGrid = char_find_pos_2d(pars()->map, 'P');
	g()->player.x = g()->playerGrid.x * SPRITE_SIZE + 32;
	g()->player.y = g()->playerGrid.y * SPRITE_SIZE + 32;
	g()->old_PlayerGrid.x = g()->playerGrid.x;
	g()->old_PlayerGrid.y = g()->playerGrid.y;
	g()->p_hitbox.top = 16;
	g()->p_hitbox.left = 12;
	g()->p_hitbox.right = 12;
	g()->p_move.spd = 10;
	lami()->grid = char_find_pos_2d(pars()->map, 'E');
	lami()->move.spd = 4;
	lami()->pos.x = lami()->grid.x * SPRITE_SIZE;
	lami()->pos.y = lami()->grid.y * SPRITE_SIZE;
	lami()->hitbox.top = 10;
	lami()->hitbox.left = 16;
	lami()->hitbox.right = 16;
	lami()->time = -1000000;
	g()->arm_range = 10;
	g()->state = START;
	g()->dev_mod = false;
	g()->mouse_id = 1;
	g()->map = allocate_2d_map(g()->window.r_width, g()->window.r_height);
	load_in_map();
	set_map(0, 0, g()->window.r_width, g()->window.r_height);
	auto_tiling((t_vec2){0, 0}, g()->window.r_width, g()->window.r_height);
}

void	init_all_tiles(void)
{
	set_grass();
	set_hill();
	set_dirt();
	set_water();
	set_sand();
	set_deep_dirt();
	set_wood_floor();
	set_wood_wall();
	set_stone_floor();
	set_stone_wall();
	set_tree();
	set_portal();
}

void	init_menu(void)
{
	menu()->button_slected = 0;
	init_menu_img(menu());
}
