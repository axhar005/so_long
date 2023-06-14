/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/14 13:53:25 by oboucher         ###   ########.fr       */
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
}