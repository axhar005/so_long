/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/20 21:59:04 by oboucher         ###   ########.fr       */
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
# define R_WIDTH 15
# define R_HEIGHT 15

// storage of pos x and y
typedef struct s_vec2
{
	int32_t			x;
	int32_t			y;
}					t_vec2;

//hitbox
typedef struct s_hitbox
{
	int32_t			top;
	int32_t			bot;
	int32_t			left;
	int32_t			right;
}					t_hitbox;

// storage of all texture (png)
typedef struct s_texture
{
	mlx_texture_t	*grass[16];
	mlx_texture_t	*dirt[16];
	mlx_texture_t	*sand[16];
	mlx_texture_t	*water[16];
	mlx_texture_t	*wall[20];
	mlx_texture_t	*player[10];
	mlx_texture_t	*selector;
	mlx_texture_t	*plank_floor;
	mlx_texture_t	*stone_floor;
	mlx_texture_t	*camera;
}					t_texture;

// storage of all image (instance)
typedef struct s_img
{
	mlx_image_t		*grass[16];
	mlx_image_t		*dirt[16];
	mlx_image_t		*sand[16];
	mlx_image_t		*water[16];
	mlx_image_t		*wall[20];
	mlx_image_t		*player[10];
	mlx_image_t		*selector;
	mlx_image_t		*plank_floor;
	mlx_image_t		*stone_floor;
	mlx_image_t		*camera;

}					t_img;

typedef struct s_map
{
	char			id;
	int32_t			tile_index;
	bool			solid;

}					t_map;

typedef struct s_animation
{
	int32_t			index;
	int32_t			loop;
	double			speed;
	double			clock;
	char			**sheet;
	char			**old_sheet;
	char			**up;
	char			**down;
	char			**left;
	char			**right;

}					t_animation;

// all game struct
typedef struct s_game
{
	char			mouse_id;
	double			delta_time;
	int32_t			player_dir;
	int32_t			arm_range;
	t_img			img;
	t_img			old_img;
	t_texture		tex;
	mlx_t			*mlx;
	t_map			***grid;
	t_vec2			playerGrid;
	t_vec2			player;
	t_vec2			cameraGrid;
	t_vec2			camera;
	t_vec2			offSet;
	t_vec2			mouse;
	t_vec2			mouseGrid;
	t_hitbox		player_hitbox;
	t_animation		player_animation;
}					t_game;

// prototype

//map

t_map				***allocate_2d_map_array(int32_t rows, int32_t cols);
void				fill_2d_map_array(t_map ***array, int32_t rows,
						int32_t cols, char c);
void				print_2d_map_array(t_map ***array, int32_t cols,
						int32_t rows);

//texture

void				init_grass_texture(mlx_texture_t **grass);
void				init_wall_texture(mlx_texture_t **wall);
void				init_sand_texture(mlx_texture_t **sand);
void				init_water_texture(mlx_texture_t **water);
void				init_player_texture(mlx_texture_t **player);
void				init_dirt_texture(mlx_texture_t **dirt);

//image

void				init_img(t_game *game, t_img *img);
void				del_img(t_game *game, t_img *img);

//string

int					ft_strnum(char **str);
char				ft_itoc(int i);

//animation

void				play_animation(t_game *game, t_animation *animation,
						char **direction);
void				init_player_animation(t_game *game);

//movement

void				player_animation_dir(t_game *game);

#endif
