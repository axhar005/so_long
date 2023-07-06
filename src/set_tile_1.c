/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/06 15:55:46 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_deep_dirt(t_map *tile)
{
	tile->name = "deep dirt";
	tile->id = DEEP_DIRT;
	tile->image = g()->img.deep_dirt;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_wood_floor(t_map *tile)
{
	tile->name = "wood floor";
	tile->id = WOOD_FLOOR;
	tile->image = g()->img.wood_floor;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_stone_floor(t_map *tile)
{
	tile->name = "stone floor";
	tile->id = STONE_FLOOR;
	tile->image = g()->img.stone_floor;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_wood_wall(t_map *tile)
{
	tile->name = "wood wall";
	tile->id = WOOD_WALL;
	tile->image = g()->img.wood_wall;
	tile->depth = WALL;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_stone_wall(t_map *tile)
{
	tile->name = "stone wall";
	tile->id = STONE_WALL;
	tile->image = g()->img.stone_wall;
	tile->depth = WALL;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}
