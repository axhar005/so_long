/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/27 23:25:29 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_deep_dirt(t_map *tile)
{
	tile->id = 5;
	tile->life = 100;
	tile->name = "deep dirt";
	tile->solid = true;
	tile->tile_index = 0;
}

void	set_plank_floor(t_map *tile)
{
	tile->id = 6;
	tile->life = 100;
	tile->name = "plank floor";
	tile->solid = false;
	tile->tile_index = 0;
}

void	set_stone_floor(t_map *tile)
{
	tile->id = 7;
	tile->life = 100;
	tile->name = "stone floor";
	tile->solid = false;
	tile->tile_index = 0;
}
