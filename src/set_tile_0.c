/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:10:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/07 11:26:01 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_grass(void)
{
	g()->tile_type[GRASS].name = "grass";
	g()->tile_type[GRASS].id = GRASS;
	g()->tile_type[GRASS].image = g()->img.grass;
	g()->tile_type[GRASS].depth = FLOOR;
	g()->tile_type[GRASS].life = 100;
	g()->tile_type[GRASS].solid = false;
	g()->tile_type[GRASS].tile_index = 0;
}

void	set_hill(void)
{
	g()->tile_type[HILL].name = "hill";
	g()->tile_type[HILL].id = HILL;
	g()->tile_type[HILL].image = g()->img.hill;
	g()->tile_type[HILL].depth = WALL;
	g()->tile_type[HILL].life = 100;
	g()->tile_type[HILL].solid = true;
	g()->tile_type[HILL].tile_index = 0;
}

void	set_dirt(void)
{
	g()->tile_type[DIRT].name = "dirt";
	g()->tile_type[DIRT].id = DIRT;
	g()->tile_type[DIRT].image = g()->img.dirt;
	g()->tile_type[DIRT].depth = FLOOR;
	g()->tile_type[DIRT].life = 100;
	g()->tile_type[DIRT].solid = false;
	g()->tile_type[DIRT].tile_index = 0;
}

void	set_water(void)
{
	g()->tile_type[WATER].name = "water";
	g()->tile_type[WATER].id = WATER;
	g()->tile_type[WATER].image = g()->img.water;
	g()->tile_type[WATER].depth = FLOOR;
	g()->tile_type[WATER].life = 100;
	g()->tile_type[WATER].solid = true;
	g()->tile_type[WATER].tile_index = 0;
}

void	set_sand(void)
{
	g()->tile_type[SAND].name = "sand";
	g()->tile_type[SAND].id = SAND;
	g()->tile_type[SAND].image = g()->img.sand;
	g()->tile_type[SAND].depth = FLOOR;
	g()->tile_type[SAND].life = 100;
	g()->tile_type[SAND].solid = false;
	g()->tile_type[SAND].tile_index = 0;
}