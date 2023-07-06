/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:10:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:49 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_grass(t_map *tile)
{
	tile->name = "grass";
	tile->id = GRASS;
	tile->image = g()->img.grass;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_hill(t_map *tile)
{
	tile->name = "hill";
	tile->id = HILL;
	tile->image = g()->img.hill;
	tile->depth = WALL;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_dirt(t_map *tile)
{
	tile->name = "dirt";
	tile->id = DIRT;
	tile->image = g()->img.dirt;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_water(t_map *tile)
{
	tile->name = "water";
	tile->id = WATER;
	tile->image = g()->img.water;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_sand(t_map *tile)
{
	tile->name = "sand";
	tile->id = SAND;
	tile->image = g()->img.sand;
	tile->depth = FLOOR;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}