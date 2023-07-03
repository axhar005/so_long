/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/03 08:57:48 by oboucher         ###   ########.fr       */
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

enum e_game
{
	SPRITE_SIZE = 64,
	WIDTH = 832,
	HEIGHT = 576,
	C_WIDTH = 13,
	C_HEIGHT = 9,
	R_WIDTH = 15,
	R_HEIGHT = 15
};

enum e_tile
{
	GRASS,
	WALL,
	DIRT,
	WATER,
	SAND,
	DEEP_DIRT,
	PLANK_FLOOR,
	STONE_FLOOR
};

// storage of pos x and y
typedef struct s_vec2
{
	int32_t			x;
	int32_t			y;
}					t_vec2;

typedef struct s_pos2
{
	t_vec2			pos1;
	t_vec2			pos2;
}					t_pos2;
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
	mlx_texture_t	*dirt[1];
	mlx_texture_t	*grass[16];
	mlx_texture_t	*deep_dirt[16];
	mlx_texture_t	*sand[16];
	mlx_texture_t	*water[16];
	mlx_texture_t	*wall[20];
	mlx_texture_t	*player[10];
	mlx_texture_t	*selector[1];
	mlx_texture_t	*plank_floor[1];
	mlx_texture_t	*stone_floor[1];
	mlx_texture_t	*crack[4];
	mlx_texture_t	*camera[1];
}					t_texture;

// storage of all image (instance)
typedef struct s_img
{
	mlx_image_t		*dirt[1];
	mlx_image_t		*grass[16];
	mlx_image_t		*deep_dirt[16];
	mlx_image_t		*sand[16];
	mlx_image_t		*water[16];
	mlx_image_t		*wall[20];
	mlx_image_t		*player[10];
	mlx_image_t		*selector[1];
	mlx_image_t		*plank_floor[1];
	mlx_image_t		*stone_floor[1];
	mlx_image_t		*crack[4];
	mlx_image_t		*camera[1];

}					t_img;

typedef struct s_map
{
	char			*name;
	int32_t			id;
	int32_t			tile_index;
	int32_t			life;
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
	double			current_time;
	int32_t			player_dir;
	int32_t			arm_range;
	t_img			img;
	t_img			old_img;
	t_texture		tex;
	mlx_t			*mlx;
	t_map			***map;
	t_map			tile_type[10];
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

//draw

void				map_image_to_window(t_game *g, mlx_image_t **img,
						t_pos2 co);
void				map_image_index_to_window(t_game *g, mlx_image_t *img,
						t_pos2 co);

//map

t_map				***allocate_2d_map_array(int32_t rows, int32_t cols);
void				fill_2d_map_array(t_map ***array, int32_t rows,
						int32_t cols, int32_t c);
void				print_2d_map_array(t_map ***array, int32_t cols,
						int32_t rows);

//texture

void				init_grass_texture(mlx_texture_t **grass);
void				init_wall_texture(mlx_texture_t **wall);
void				init_sand_texture(mlx_texture_t **sand);
void				init_water_texture(mlx_texture_t **water);
void				init_player_texture(mlx_texture_t **player);
void				init_deep_dirt_texture(mlx_texture_t **deep_dirt);
void			    init_crack_texture(mlx_texture_t **crack);

//image

void				init_img(t_game *game, t_img *img);
void				del_img(t_game *game, t_img *img);

//tiling

void				auto_tiling(t_game *game, int32_t x, int32_t y,
						int32_t width, int32_t height);
int32_t				point_distance(t_vec2 bow, t_vec2 target);

//tile type

void				set_grass(t_map *tile);
void				set_wall(t_map *tile);
void				set_dirt(t_map *tile);
void				set_water(t_map *tile);
void				set_sand(t_map *tile);
void				set_deep_dirt(t_map *tile);
void				set_plank_floor(t_map *tile);
void				set_stone_floor(t_map *tile);

//string

int					ft_strnum(char **str);
char				ft_itoc(int i);

//collision

bool				tile_collision(int x, int y, int w, int h, int32_t c);

//animation

void				play_animation(t_game *game, t_animation *animation,
						char **direction);
void				init_player_animation(t_game *game);
bool				is_tilable(int32_t id);

//movement

void				movement(t_vec2 *pos, int32_t *dir, t_hitbox hitbox,
						bool is_vertical);
void				player_animation_dir(t_game *game);

//math

int					sign(int nb);
bool				is_even(int nb);

#endif
