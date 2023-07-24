/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:35 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/24 16:43:18 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	map_image_to_window(mlx_image_t **img, t_pos2 co, bool under)
{
	int32_t	p1x;
	int32_t	p1y;

	p1x = co.pos1.x;
	p1y = co.pos1.y;
	if (under)
	{
		mlx_image_to_window(g()->mlx,
							img[g()->map[p1x][p1y]->under.tile_index],
							(co.pos2.x * SPRITE_SIZE) - g()->offSet.x,
							(co.pos2.y * SPRITE_SIZE) - g()->offSet.y);
	}
	else
	{
		mlx_image_to_window(g()->mlx,
							img[g()->map[p1x][p1y]->tile_index],
							(co.pos2.x * SPRITE_SIZE) - g()->offSet.x,
							(co.pos2.y * SPRITE_SIZE) - g()->offSet.y);
	}
}

void	map_image_index_to_window(mlx_image_t *img, t_pos2 co)
{
	mlx_image_to_window(g()->mlx, img, (co.pos2.x * SPRITE_SIZE)
			- g()->offSet.x, (co.pos2.y * SPRITE_SIZE) - g()->offSet.y);
}

void	draw_crack(t_pos2 co)
{
	int32_t	life;

	if (g()->map[co.pos1.x][co.pos1.y]->name)
	{
		life = g()->map[co.pos1.x][co.pos1.y]->life;
		if (life >= 75 && life < 100)
			map_image_index_to_window(g()->img.crack[0], co);
		else if (life >= 50 && life < 75)
			map_image_index_to_window(g()->img.crack[1], co);
		else if (life >= 25 && life < 50)
			map_image_index_to_window(g()->img.crack[2], co);
		else if (life < 25)
			map_image_index_to_window(g()->img.crack[3], co);
	}
}

static void	norm1(t_tile ***map, t_pos2 co)
{
	if (map[co.pos1.x][co.pos1.y]->under.image)
		map_image_to_window(map[co.pos1.x][co.pos1.y]->under.image, co, true);
	if (map[co.pos1.x][co.pos1.y]->image)
		map_image_to_window(map[co.pos1.x][co.pos1.y]->image, co, false);
	auto_tiling_corner(g()->img.hill, co, HILL);
	auto_tiling_corner(g()->img.wood_wall, co, WOOD_WALL);
	auto_tiling_corner(g()->img.stone_wall, co, STONE_WALL);
	draw_crack(co);
}

void	draw_grid(int32_t posX, int32_t posY, t_tile ***map)
{
	t_pos2 co;

	del_img(&g()->old_img);
	g()->old_img = g()->img;
	init_img(&g()->img);
	mlx_image_to_window(g()->mlx, g()->img.grass[0], -1000, 0);
	co.pos2.x = -1;
	while (co.pos2.x < g()->window.c_width + 1)
	{
		co.pos2.y = -1;
		while (co.pos2.y < g()->window.c_height + 1)
		{
			co.pos1.x = co.pos2.x + posX;
			co.pos1.y = co.pos2.y + posY;
			if ((co.pos1.x >= 0 && co.pos1.x < g()->window.r_width)
				&& (co.pos1.y >= 0 && co.pos1.y < g()->window.r_height))
			{
				norm1(map, co);
			}
			co.pos2.y++;
		}
		co.pos2.x++;
	}
}