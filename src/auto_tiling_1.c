/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_tiling_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:31:12 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 13:40:10 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(mlx_image_t **img, t_pos2 co, int32_t id)
{
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 4)
	{
		if (g()->map[co.pos1.x - 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[16], co);
		if (g()->map[co.pos1.x + 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[17], co);
		if (g()->map[co.pos1.x - 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[18], co);
		if (g()->map[co.pos1.x + 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[19], co);
	}
}

static void	norm2(mlx_image_t **img, t_pos2 co, int32_t id)
{
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 0)
		if (g()->map[co.pos1.x + 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[19], co);
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 1)
	{
		if (g()->map[co.pos1.x - 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[18], co);
		if (g()->map[co.pos1.x + 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[19], co);
	}
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 2)
		if (g()->map[co.pos1.x - 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[18], co);
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 3)
	{
		if (g()->map[co.pos1.x + 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[17], co);
		if (g()->map[co.pos1.x + 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[19], co);
	}
}

static void	norm3(mlx_image_t **img, t_pos2 co, int32_t id)
{
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 5)
	{
		if (g()->map[co.pos1.x - 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[16], co);
		if (g()->map[co.pos1.x - 1][co.pos1.y + 1]->id != id)
			map_image_index_to_window(img[18], co);
	}
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 6)
		if (g()->map[co.pos1.x + 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[17], co);
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 7)
	{
		if (g()->map[co.pos1.x - 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[16], co);
		if (g()->map[co.pos1.x + 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[17], co);
	}
	if (g()->map[co.pos1.x][co.pos1.y]->tile_index == 8)
		if (g()->map[co.pos1.x - 1][co.pos1.y - 1]->id != id)
			map_image_index_to_window(img[16], co);
}

/// @brief draw auto_tiling corner
void	auto_tiling_corner(mlx_image_t **img, t_pos2 co, int32_t id)
{
	if (g()->map[co.pos1.x][co.pos1.y]->id == id)
	{
		norm1(img, co, id);
		norm2(img, co, id);
		norm3(img, co, id);
	}
}
