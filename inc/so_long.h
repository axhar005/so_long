/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/15 12:37:58 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// struct

# define SPRITE_SIZE 64
# define WIDTH 832
# define HEIGHT 576
# define C_WIDTH 13
# define C_HEIGHT 9
# define R_WIDTH 20
# define R_HEIGHT 20

// storage of pos x and y
typedef struct s_vec2
{
	int32_t			x;
	int32_t			y;
}					t_vec2;

// storage of all texture (png)
typedef struct s_texture
{
	mlx_texture_t	*grass[16];
	mlx_texture_t	*sand[16];
	mlx_texture_t	*water[16];
	mlx_texture_t	*wall[20];
	mlx_texture_t	*player[10];
	mlx_texture_t	*camera;
}					t_texture;

// storage of all image (instance)
typedef struct s_img
{
	mlx_image_t		*grass[16];
	mlx_image_t		*sand[16];
	mlx_image_t		*water[16];
	mlx_image_t		*wall[20];
	mlx_image_t		*player;
	mlx_image_t		*camera;

}					t_img;

typedef struct s_map
{
	char			id;
	int32_t			tile_index;
	bool			solid;

}					t_map;

// all game struct
typedef struct s_game
{
	t_img			img;
	t_img			old_img;
	t_texture		tex;
	mlx_t			*mlx;
	double			delta_time;
	t_map			***grid;
	t_vec2			playerGrid;
	t_vec2			player;
	t_vec2			cameraGrid;
	t_vec2			camera;
	t_vec2			offSet;
}					t_game;

// prototype

t_map				***allocate_2d_map_array(int32_t rows, int32_t cols);
void				fill_2d_map_array(t_map ***array, int32_t rows,
						int32_t cols, char c);
void				print_2d_map_array(t_map ***array);
void				init_grass_texture(mlx_texture_t **grass);
void				init_wall_texture(mlx_texture_t **wall);
void				init_sand_texture(mlx_texture_t **sand);
void				init_water_texture(mlx_texture_t **water);

#endif