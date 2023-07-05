/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/04 20:23:38 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_deep_dirt(t_map *tile)
{
	tile->name = "deep dirt";
	tile->id = 5;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_plank_floor(t_map *tile)
{
	tile->name = "plank floor";
	tile->id = 6;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_stone_floor(t_map *tile)
{
	tile->name = "stone floor";
	tile->id = 7;
	tile->depth = FLOORS;
	tile->life = 100;
	tile->solid = false;
	tile->tile_index = 0;
}
