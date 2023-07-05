/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:10:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/04 20:50:21 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_grass(t_map *tile)
{
	tile->name = "grass";
	tile->id = 0;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_wall(t_map *tile)
{
	tile->name = "wall";
	tile->id = 1;
	tile->depth = WALLS;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_dirt(t_map *tile)
{
	tile->name = "dirt";
	tile->id = 2;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_water(t_map *tile)
{
	tile->name = "water";
	tile->id = 3;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_sand(t_map *tile)
{
	tile->name = "sand";
	tile->id = 4;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}