/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/07 11:25:57 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_deep_dirt(void)
{
	g()->tile_type[DEEP_DIRT].name = "deep dirt";
	g()->tile_type[DEEP_DIRT].id = DEEP_DIRT;
	g()->tile_type[DEEP_DIRT].image = g()->img.deep_dirt;
	g()->tile_type[DEEP_DIRT].depth = FLOOR;
	g()->tile_type[DEEP_DIRT].life = 100;
	g()->tile_type[DEEP_DIRT].solid = true;
	g()->tile_type[DEEP_DIRT].tile_index = 0;
}

void	set_wood_floor(void)
{
	g()->tile_type[WOOD_FLOOR].name = "wood floor";
	g()->tile_type[WOOD_FLOOR].id = WOOD_FLOOR;
	g()->tile_type[WOOD_FLOOR].image = g()->img.wood_floor;
	g()->tile_type[WOOD_FLOOR].depth = FLOOR;
	g()->tile_type[WOOD_FLOOR].life = 100;
	g()->tile_type[WOOD_FLOOR].solid = false;
	g()->tile_type[WOOD_FLOOR].tile_index = 0;
}

void	set_stone_floor(void)
{
	g()->tile_type[STONE_FLOOR].name = "stone floor";
	g()->tile_type[STONE_FLOOR].id = STONE_FLOOR;
	g()->tile_type[STONE_FLOOR].image = g()->img.stone_floor;
	g()->tile_type[STONE_FLOOR].depth = FLOOR;
	g()->tile_type[STONE_FLOOR].life = 100;
	g()->tile_type[STONE_FLOOR].solid = false;
	g()->tile_type[STONE_FLOOR].tile_index = 0;
}

void	set_wood_wall(void)
{
	g()->tile_type[WOOD_WALL].name = "wood wall";
	g()->tile_type[WOOD_WALL].id = WOOD_WALL;
	g()->tile_type[WOOD_WALL].image = g()->img.wood_wall;
	g()->tile_type[WOOD_WALL].depth = WALL;
	g()->tile_type[WOOD_WALL].life = 100;
	g()->tile_type[WOOD_WALL].solid = true;
	g()->tile_type[WOOD_WALL].tile_index = 0;
}

void	set_stone_wall(void)
{
	g()->tile_type[STONE_WALL].name = "stone wall";
	g()->tile_type[STONE_WALL].id = STONE_WALL;
	g()->tile_type[STONE_WALL].image = g()->img.stone_wall;
	g()->tile_type[STONE_WALL].depth = WALL;
	g()->tile_type[STONE_WALL].life = 100;
	g()->tile_type[STONE_WALL].solid = true;
	g()->tile_type[STONE_WALL].tile_index = 0;
}
