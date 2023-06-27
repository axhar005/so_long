/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:10:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/27 15:17:30 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_grass(t_map *tile)
{
	tile->id = 0;
	tile->name = "grass";
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_wall(t_map *tile)
{
	tile->id = 1;
	tile->name = "wall";
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_dirt(t_map *tile)
{
	tile->id = 2;
	tile->name = "dirt";
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_water(t_map *tile)
{
	tile->id = 3;
	tile->name = "water";
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_sand(t_map *tile)
{
	tile->id = 4;
	tile->name = "sand";
	tile->solid = false;
	tile->tile_index = 0;
}