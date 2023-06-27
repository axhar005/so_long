/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/26 15:48:43 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    init_grass_texture(mlx_texture_t **grass)
{   
    grass[0] = mlx_load_png("./asset/grass/grass_0.png");
	grass[1] = mlx_load_png("./asset/grass/grass_1.png");
	grass[2] = mlx_load_png("./asset/grass/grass_2.png");
	grass[3] = mlx_load_png("./asset/grass/grass_3.png");
	grass[4] = mlx_load_png("./asset/grass/grass_4.png");
	grass[5] = mlx_load_png("./asset/grass/grass_5.png");
	grass[6] = mlx_load_png("./asset/grass/grass_6.png");
	grass[7] = mlx_load_png("./asset/grass/grass_7.png");
	grass[8] = mlx_load_png("./asset/grass/grass_8.png");
    grass[9] = mlx_load_png("./asset/grass/grass_9.png");
	grass[10] = mlx_load_png("./asset/grass/grass_10.png");
	grass[11] = mlx_load_png("./asset/grass/grass_11.png");
	grass[12] = mlx_load_png("./asset/grass/grass_12.png");
	grass[13] = mlx_load_png("./asset/grass/grass_13.png");
	grass[14] = mlx_load_png("./asset/grass/grass_14.png");
	grass[15] = mlx_load_png("./asset/grass/grass_15.png");
}

void    init_sand_texture(mlx_texture_t **sand)
{   
    sand[0] = mlx_load_png("./asset/sand/sand_0.png");
	sand[1] = mlx_load_png("./asset/sand/sand_1.png");
	sand[2] = mlx_load_png("./asset/sand/sand_2.png");
	sand[3] = mlx_load_png("./asset/sand/sand_3.png");
	sand[4] = mlx_load_png("./asset/sand/sand_4.png");
	sand[5] = mlx_load_png("./asset/sand/sand_5.png");
	sand[6] = mlx_load_png("./asset/sand/sand_6.png");
	sand[7] = mlx_load_png("./asset/sand/sand_7.png");
	sand[8] = mlx_load_png("./asset/sand/sand_8.png");
    sand[9] = mlx_load_png("./asset/sand/sand_9.png");
	sand[10] = mlx_load_png("./asset/sand/sand_10.png");
	sand[11] = mlx_load_png("./asset/sand/sand_11.png");
	sand[12] = mlx_load_png("./asset/sand/sand_12.png");
	sand[13] = mlx_load_png("./asset/sand/sand_13.png");
	sand[14] = mlx_load_png("./asset/sand/sand_14.png");
	sand[15] = mlx_load_png("./asset/sand/sand_15.png");
}

void    init_water_texture(mlx_texture_t **water)
{   
    water[0] = mlx_load_png("./asset/water/water_0.png");
	water[1] = mlx_load_png("./asset/water/water_1.png");
	water[2] = mlx_load_png("./asset/water/water_2.png");
	water[3] = mlx_load_png("./asset/water/water_3.png");
	water[4] = mlx_load_png("./asset/water/water_4.png");
	water[5] = mlx_load_png("./asset/water/water_5.png");
	water[6] = mlx_load_png("./asset/water/water_6.png");
	water[7] = mlx_load_png("./asset/water/water_7.png");
	water[8] = mlx_load_png("./asset/water/water_8.png");
    water[9] = mlx_load_png("./asset/water/water_9.png");
	water[10] = mlx_load_png("./asset/water/water_10.png");
	water[11] = mlx_load_png("./asset/water/water_11.png");
	water[12] = mlx_load_png("./asset/water/water_12.png");
	water[13] = mlx_load_png("./asset/water/water_13.png");
	water[14] = mlx_load_png("./asset/water/water_14.png");
	water[15] = mlx_load_png("./asset/water/water_15.png");
}

void    init_wall_texture(mlx_texture_t **wall)
{   
    wall[0] = mlx_load_png("./asset/wall/wall_0.png");
	wall[1] = mlx_load_png("./asset/wall/wall_1.png");
	wall[2] = mlx_load_png("./asset/wall/wall_2.png");
	wall[3] = mlx_load_png("./asset/wall/wall_3.png");
	wall[4] = mlx_load_png("./asset/wall/wall_4.png");
	wall[5] = mlx_load_png("./asset/wall/wall_5.png");
	wall[6] = mlx_load_png("./asset/wall/wall_6.png");
	wall[7] = mlx_load_png("./asset/wall/wall_7.png");
	wall[8] = mlx_load_png("./asset/wall/wall_8.png");
    wall[9] = mlx_load_png("./asset/wall/wall_9.png");
	wall[10] = mlx_load_png("./asset/wall/wall_10.png");
	wall[11] = mlx_load_png("./asset/wall/wall_11.png");
	wall[12] = mlx_load_png("./asset/wall/wall_12.png");
	wall[13] = mlx_load_png("./asset/wall/wall_13.png");
	wall[14] = mlx_load_png("./asset/wall/wall_14.png");
	wall[15] = mlx_load_png("./asset/wall/wall_15.png");
	wall[16] = mlx_load_png("./asset/wall/wall_16.png");
	wall[17] = mlx_load_png("./asset/wall/wall_17.png");
	wall[18] = mlx_load_png("./asset/wall/wall_18.png");
	wall[19] = mlx_load_png("./asset/wall/wall_19.png");
}

void    init_player_texture(mlx_texture_t **player)
{   
    player[0] = mlx_load_png("./asset/player/player_down_0.png");
	player[1] = mlx_load_png("./asset/player/player_down_1.png");
	player[2] = mlx_load_png("./asset/player/player_up_0.png");
	player[3] = mlx_load_png("./asset/player/player_up_1.png");
	player[4] = mlx_load_png("./asset/player/player_left_0.png");
	player[5] = mlx_load_png("./asset/player/player_left_1.png");
	player[6] = mlx_load_png("./asset/player/player_left_2.png");
	player[7] = mlx_load_png("./asset/player/player_right_0.png");
	player[8] = mlx_load_png("./asset/player/player_right_1.png");
    player[9] = mlx_load_png("./asset/player/player_right_2.png");
}

void    init_deep_dirt_texture(mlx_texture_t **deep_dirt)
{   
	deep_dirt[0] = mlx_load_png("./asset/deep_dirt/deep_dirt_0.png");
	deep_dirt[1] = mlx_load_png("./asset/deep_dirt/deep_dirt_1.png");
	deep_dirt[2] = mlx_load_png("./asset/deep_dirt/deep_dirt_2.png");
	deep_dirt[3] = mlx_load_png("./asset/deep_dirt/deep_dirt_3.png");
	deep_dirt[4] = mlx_load_png("./asset/deep_dirt/deep_dirt_4.png");
	deep_dirt[5] = mlx_load_png("./asset/deep_dirt/deep_dirt_5.png");
	deep_dirt[6] = mlx_load_png("./asset/deep_dirt/deep_dirt_6.png");
	deep_dirt[7] = mlx_load_png("./asset/deep_dirt/deep_dirt_7.png");
	deep_dirt[8] = mlx_load_png("./asset/deep_dirt/deep_dirt_8.png");
    deep_dirt[9] = mlx_load_png("./asset/deep_dirt/deep_dirt_9.png");
	deep_dirt[10] = mlx_load_png("./asset/deep_dirt/deep_dirt_10.png");
	deep_dirt[11] = mlx_load_png("./asset/deep_dirt/deep_dirt_11.png");
	deep_dirt[12] = mlx_load_png("./asset/deep_dirt/deep_dirt_12.png");
	deep_dirt[13] = mlx_load_png("./asset/deep_dirt/deep_dirt_13.png");
	deep_dirt[14] = mlx_load_png("./asset/deep_dirt/deep_dirt_14.png");
	deep_dirt[15] = mlx_load_png("./asset/deep_dirt/deep_dirt_15.png");
}