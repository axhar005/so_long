/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:10:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 16:58:07 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_grass(t_map *tile)
{
	tile->name = "grass";
	tile->id = GRASS;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_hill(t_map *tile)
{
	tile->name = "hill";
	tile->id = HILL;
	tile->depth = WALLS;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_dirt(t_map *tile)
{
	tile->name = "dirt";
	tile->id = DIRT;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_water(t_map *tile)
{
	tile->name = "water";
	tile->id = WATER;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_sand(t_map *tile)
{
	tile->name = "sand";
	tile->id = SAND;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}