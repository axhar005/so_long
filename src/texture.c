/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/06 09:19:18 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_grass_texture(void)
{
	g()->tex.grass[0] = mlx_load_png("./asset/grass/grass_0.png");
	g()->tex.grass[1] = mlx_load_png("./asset/grass/grass_1.png");
	g()->tex.grass[2] = mlx_load_png("./asset/grass/grass_2.png");
	g()->tex.grass[3] = mlx_load_png("./asset/grass/grass_3.png");
	g()->tex.grass[4] = mlx_load_png("./asset/grass/grass_4.png");
	g()->tex.grass[5] = mlx_load_png("./asset/grass/grass_5.png");
	g()->tex.grass[6] = mlx_load_png("./asset/grass/grass_6.png");
	g()->tex.grass[7] = mlx_load_png("./asset/grass/grass_7.png");
	g()->tex.grass[8] = mlx_load_png("./asset/grass/grass_8.png");
	g()->tex.grass[9] = mlx_load_png("./asset/grass/grass_9.png");
	g()->tex.grass[10] = mlx_load_png("./asset/grass/grass_10.png");
	g()->tex.grass[11] = mlx_load_png("./asset/grass/grass_11.png");
	g()->tex.grass[12] = mlx_load_png("./asset/grass/grass_12.png");
	g()->tex.grass[13] = mlx_load_png("./asset/grass/grass_13.png");
	g()->tex.grass[14] = mlx_load_png("./asset/grass/grass_14.png");
	g()->tex.grass[15] = mlx_load_png("./asset/grass/grass_15.png");
}

void	init_sand_texture(void)
{
	g()->tex.sand[0] = mlx_load_png("./asset/sand/sand_0.png");
	g()->tex.sand[1] = mlx_load_png("./asset/sand/sand_1.png");
	g()->tex.sand[2] = mlx_load_png("./asset/sand/sand_2.png");
	g()->tex.sand[3] = mlx_load_png("./asset/sand/sand_3.png");
	g()->tex.sand[4] = mlx_load_png("./asset/sand/sand_4.png");
	g()->tex.sand[5] = mlx_load_png("./asset/sand/sand_5.png");
	g()->tex.sand[6] = mlx_load_png("./asset/sand/sand_6.png");
	g()->tex.sand[7] = mlx_load_png("./asset/sand/sand_7.png");
	g()->tex.sand[8] = mlx_load_png("./asset/sand/sand_8.png");
	g()->tex.sand[9] = mlx_load_png("./asset/sand/sand_9.png");
	g()->tex.sand[10] = mlx_load_png("./asset/sand/sand_10.png");
	g()->tex.sand[11] = mlx_load_png("./asset/sand/sand_11.png");
	g()->tex.sand[12] = mlx_load_png("./asset/sand/sand_12.png");
	g()->tex.sand[13] = mlx_load_png("./asset/sand/sand_13.png");
	g()->tex.sand[14] = mlx_load_png("./asset/sand/sand_14.png");
	g()->tex.sand[15] = mlx_load_png("./asset/sand/sand_15.png");
}

void	init_water_texture(void)
{
	g()->tex.water[0] = mlx_load_png("./asset/water/water_0.png");
	g()->tex.water[1] = mlx_load_png("./asset/water/water_1.png");
	g()->tex.water[2] = mlx_load_png("./asset/water/water_2.png");
	g()->tex.water[3] = mlx_load_png("./asset/water/water_3.png");
	g()->tex.water[4] = mlx_load_png("./asset/water/water_4.png");
	g()->tex.water[5] = mlx_load_png("./asset/water/water_5.png");
	g()->tex.water[6] = mlx_load_png("./asset/water/water_6.png");
	g()->tex.water[7] = mlx_load_png("./asset/water/water_7.png");
	g()->tex.water[8] = mlx_load_png("./asset/water/water_8.png");
	g()->tex.water[9] = mlx_load_png("./asset/water/water_9.png");
	g()->tex.water[10] = mlx_load_png("./asset/water/water_10.png");
	g()->tex.water[11] = mlx_load_png("./asset/water/water_11.png");
	g()->tex.water[12] = mlx_load_png("./asset/water/water_12.png");
	g()->tex.water[13] = mlx_load_png("./asset/water/water_13.png");
	g()->tex.water[14] = mlx_load_png("./asset/water/water_14.png");
	g()->tex.water[15] = mlx_load_png("./asset/water/water_15.png");
}

void	init_hill_texture(void)
{
	g()->tex.hill[0] = mlx_load_png("./asset/hill/hill_0.png");
	g()->tex.hill[1] = mlx_load_png("./asset/hill/hill_1.png");
	g()->tex.hill[2] = mlx_load_png("./asset/hill/hill_2.png");
	g()->tex.hill[3] = mlx_load_png("./asset/hill/hill_3.png");
	g()->tex.hill[4] = mlx_load_png("./asset/hill/hill_4.png");
	g()->tex.hill[5] = mlx_load_png("./asset/hill/hill_5.png");
	g()->tex.hill[6] = mlx_load_png("./asset/hill/hill_6.png");
	g()->tex.hill[7] = mlx_load_png("./asset/hill/hill_7.png");
	g()->tex.hill[8] = mlx_load_png("./asset/hill/hill_8.png");
	g()->tex.hill[9] = mlx_load_png("./asset/hill/hill_9.png");
	g()->tex.hill[10] = mlx_load_png("./asset/hill/hill_10.png");
	g()->tex.hill[11] = mlx_load_png("./asset/hill/hill_11.png");
	g()->tex.hill[12] = mlx_load_png("./asset/hill/hill_12.png");
	g()->tex.hill[13] = mlx_load_png("./asset/hill/hill_13.png");
	g()->tex.hill[14] = mlx_load_png("./asset/hill/hill_14.png");
	g()->tex.hill[15] = mlx_load_png("./asset/hill/hill_15.png");
	g()->tex.hill[16] = mlx_load_png("./asset/hill/hill_16.png");
	g()->tex.hill[17] = mlx_load_png("./asset/hill/hill_17.png");
	g()->tex.hill[18] = mlx_load_png("./asset/hill/hill_18.png");
	g()->tex.hill[19] = mlx_load_png("./asset/hill/hill_19.png");
}

void	init_wood_wall_texture(void)
{
	g()->tex.wood_wall[0] = mlx_load_png("./asset/wood/wood_wall/wood_wall_0.png");
	g()->tex.wood_wall[1] = mlx_load_png("./asset/wood/wood_wall/wood_wall_1.png");
	g()->tex.wood_wall[2] = mlx_load_png("./asset/wood/wood_wall/wood_wall_2.png");
	g()->tex.wood_wall[3] = mlx_load_png("./asset/wood/wood_wall/wood_wall_3.png");
	g()->tex.wood_wall[4] = mlx_load_png("./asset/wood/wood_wall/wood_wall_4.png");
	g()->tex.wood_wall[5] = mlx_load_png("./asset/wood/wood_wall/wood_wall_5.png");
	g()->tex.wood_wall[6] = mlx_load_png("./asset/wood/wood_wall/wood_wall_6.png");
	g()->tex.wood_wall[7] = mlx_load_png("./asset/wood/wood_wall/wood_wall_7.png");
	g()->tex.wood_wall[8] = mlx_load_png("./asset/wood/wood_wall/wood_wall_8.png");
	g()->tex.wood_wall[9] = mlx_load_png("./asset/wood/wood_wall/wood_wall_9.png");
	g()->tex.wood_wall[10] = mlx_load_png("./asset/wood/wood_wall/wood_wall_10.png");
	g()->tex.wood_wall[11] = mlx_load_png("./asset/wood/wood_wall/wood_wall_11.png");
	g()->tex.wood_wall[12] = mlx_load_png("./asset/wood/wood_wall/wood_wall_12.png");
	g()->tex.wood_wall[13] = mlx_load_png("./asset/wood/wood_wall/wood_wall_13.png");
	g()->tex.wood_wall[14] = mlx_load_png("./asset/wood/wood_wall/wood_wall_14.png");
	g()->tex.wood_wall[15] = mlx_load_png("./asset/wood/wood_wall/wood_wall_15.png");
	g()->tex.wood_wall[16] = mlx_load_png("./asset/wood/wood_wall/wood_wall_16.png");
	g()->tex.wood_wall[17] = mlx_load_png("./asset/wood/wood_wall/wood_wall_17.png");
	g()->tex.wood_wall[18] = mlx_load_png("./asset/wood/wood_wall/wood_wall_18.png");
	g()->tex.wood_wall[19] = mlx_load_png("./asset/wood/wood_wall/wood_wall_19.png");
}

void	init_stone_wall_texture(void)
{
	g()->tex.stone_wall[0] = mlx_load_png("./asset/stone/stone_wall/stone_wall_0.png");
	g()->tex.stone_wall[1] = mlx_load_png("./asset/stone/stone_wall/stone_wall_1.png");
	g()->tex.stone_wall[2] = mlx_load_png("./asset/stone/stone_wall/stone_wall_2.png");
	g()->tex.stone_wall[3] = mlx_load_png("./asset/stone/stone_wall/stone_wall_3.png");
	g()->tex.stone_wall[4] = mlx_load_png("./asset/stone/stone_wall/stone_wall_4.png");
	g()->tex.stone_wall[5] = mlx_load_png("./asset/stone/stone_wall/stone_wall_5.png");
	g()->tex.stone_wall[6] = mlx_load_png("./asset/stone/stone_wall/stone_wall_6.png");
	g()->tex.stone_wall[7] = mlx_load_png("./asset/stone/stone_wall/stone_wall_7.png");
	g()->tex.stone_wall[8] = mlx_load_png("./asset/stone/stone_wall/stone_wall_8.png");
	g()->tex.stone_wall[9] = mlx_load_png("./asset/stone/stone_wall/stone_wall_9.png");
	g()->tex.stone_wall[10] = mlx_load_png("./asset/stone/stone_wall/stone_wall_10.png");
	g()->tex.stone_wall[11] = mlx_load_png("./asset/stone/stone_wall/stone_wall_11.png");
	g()->tex.stone_wall[12] = mlx_load_png("./asset/stone/stone_wall/stone_wall_12.png");
	g()->tex.stone_wall[13] = mlx_load_png("./asset/stone/stone_wall/stone_wall_13.png");
	g()->tex.stone_wall[14] = mlx_load_png("./asset/stone/stone_wall/stone_wall_14.png");
	g()->tex.stone_wall[15] = mlx_load_png("./asset/stone/stone_wall/stone_wall_15.png");
	g()->tex.stone_wall[16] = mlx_load_png("./asset/stone/stone_wall/stone_wall_16.png");
	g()->tex.stone_wall[17] = mlx_load_png("./asset/stone/stone_wall/stone_wall_17.png");
	g()->tex.stone_wall[18] = mlx_load_png("./asset/stone/stone_wall/stone_wall_18.png");
	g()->tex.stone_wall[19] = mlx_load_png("./asset/stone/stone_wall/stone_wall_19.png");
}

void	init_deep_dirt_texture(void)
{
	g()->tex.deep_dirt[0] = mlx_load_png("./asset/deep_dirt/deep_dirt_0.png");
	g()->tex.deep_dirt[1] = mlx_load_png("./asset/deep_dirt/deep_dirt_1.png");
	g()->tex.deep_dirt[2] = mlx_load_png("./asset/deep_dirt/deep_dirt_2.png");
	g()->tex.deep_dirt[3] = mlx_load_png("./asset/deep_dirt/deep_dirt_3.png");
	g()->tex.deep_dirt[4] = mlx_load_png("./asset/deep_dirt/deep_dirt_4.png");
	g()->tex.deep_dirt[5] = mlx_load_png("./asset/deep_dirt/deep_dirt_5.png");
	g()->tex.deep_dirt[6] = mlx_load_png("./asset/deep_dirt/deep_dirt_6.png");
	g()->tex.deep_dirt[7] = mlx_load_png("./asset/deep_dirt/deep_dirt_7.png");
	g()->tex.deep_dirt[8] = mlx_load_png("./asset/deep_dirt/deep_dirt_8.png");
	g()->tex.deep_dirt[9] = mlx_load_png("./asset/deep_dirt/deep_dirt_9.png");
	g()->tex.deep_dirt[10] = mlx_load_png("./asset/deep_dirt/deep_dirt_10.png");
	g()->tex.deep_dirt[11] = mlx_load_png("./asset/deep_dirt/deep_dirt_11.png");
	g()->tex.deep_dirt[12] = mlx_load_png("./asset/deep_dirt/deep_dirt_12.png");
	g()->tex.deep_dirt[13] = mlx_load_png("./asset/deep_dirt/deep_dirt_13.png");
	g()->tex.deep_dirt[14] = mlx_load_png("./asset/deep_dirt/deep_dirt_14.png");
	g()->tex.deep_dirt[15] = mlx_load_png("./asset/deep_dirt/deep_dirt_15.png");
}

void	init_player_texture(void)
{
	g()->tex.player[0] = mlx_load_png("./asset/player/player_down_0.png");
	g()->tex.player[1] = mlx_load_png("./asset/player/player_down_1.png");
	g()->tex.player[2] = mlx_load_png("./asset/player/player_up_0.png");
	g()->tex.player[3] = mlx_load_png("./asset/player/player_up_1.png");
	g()->tex.player[4] = mlx_load_png("./asset/player/player_left_0.png");
	g()->tex.player[5] = mlx_load_png("./asset/player/player_left_1.png");
	g()->tex.player[6] = mlx_load_png("./asset/player/player_left_2.png");
	g()->tex.player[7] = mlx_load_png("./asset/player/player_right_0.png");
	g()->tex.player[8] = mlx_load_png("./asset/player/player_right_1.png");
	g()->tex.player[9] = mlx_load_png("./asset/player/player_right_2.png");
}

void	init_crack_texture(void)
{
	g()->tex.crack[0] = mlx_load_png("./asset/crack/crack_0.png");
	g()->tex.crack[1] = mlx_load_png("./asset/crack/crack_1.png");
	g()->tex.crack[2] = mlx_load_png("./asset/crack/crack_2.png");
	g()->tex.crack[3] = mlx_load_png("./asset/crack/crack_3.png");
}