/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:23:26 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 13:19:06 by olivierbouc      ###   ########.fr       */
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

static	void	init_lami_val(void)
{
	t_lami	*la;

	la = lami();
	la->grid = char_find_pos_2d(pars()->map, 'E');
	la->move.spd = 4;
	la->pos.x = lami()->grid.x * SPRITE_SIZE;
	la->pos.y = lami()->grid.y * SPRITE_SIZE;
	la->hitbox.top = 10;
	la->hitbox.left = 16;
	la->hitbox.right = 16;
	la->time = -1000000;
}

void	init_val(void)
{
	t_game	*ga;

	ga = g();
	ga->playerGrid = char_find_pos_2d(pars()->map, 'P');
	ga->player.x = g()->playerGrid.x * SPRITE_SIZE + 32;
	ga->player.y = g()->playerGrid.y * SPRITE_SIZE + 32;
	ga->old_PlayerGrid.x = g()->playerGrid.x;
	ga->old_PlayerGrid.y = g()->playerGrid.y;
	ga->p_hitbox.top = 16;
	ga->p_hitbox.left = 12;
	ga->p_hitbox.right = 12;
	ga->p_move.spd = 10;
	ga->arm_range = 10;
	ga->state = START;
	ga->mouse_id = 1;
	ga->map = allocate_2d_map(g()->window.r_width, g()->window.r_height);
	init_lami_val();
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
