/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/10 14:17:05 by olivierbouc      ###   ########.fr       */
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

enum				e_game
{
	SPRITE_SIZE = 64
};

enum				e_depth
{
	FLOOR,
	WALL
};

enum				e_states
{
	START,
	INVENTORY,
	GAME
};
enum				e_tile
{
	NOTHING,
	GRASS,
	HILL,
	DIRT,
	WATER,
	SAND,
	DEEP_DIRT,
	WOOD_FLOOR,
	WOOD_WALL,
	STONE_FLOOR,
	STONE_WALL,
	TREE
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

typedef struct s_menu
{
	int32_t			button_slected;
	mlx_image_t		*background;
	mlx_image_t		*button[2];
}					t_menu;

typedef struct s_window
{
	int32_t			height;
	int32_t			width;
	int32_t			c_height;
	int32_t			c_width;
	int32_t			r_height;
	int32_t			r_width;
}					t_window;

// hitbox
typedef struct s_hitbox
{
	int32_t			top;
	int32_t			bot;
	int32_t			left;
	int32_t			right;
}					t_hitbox;

// movement
typedef struct s_movement
{
	int32_t			hspd;
	int32_t			vspd;
	int32_t			spd;
}					t_movement;

// storage of all texture (png)
typedef struct s_texture
{
	mlx_texture_t	*dirt[1];
	mlx_texture_t	*grass[16];
	mlx_texture_t	*deep_dirt[16];
	mlx_texture_t	*sand[16];
	mlx_texture_t	*water[16];
	mlx_texture_t	*hill[20];
	mlx_texture_t	*player[10];
	mlx_texture_t	*selector[1];
	mlx_texture_t	*wood_floor[1];
	mlx_texture_t	*wood_wall[20];
	mlx_texture_t	*stone_floor[1];
	mlx_texture_t	*stone_wall[20];
	mlx_texture_t	*crack[4];
	mlx_texture_t	*tree[1];
}					t_texture;

// storage of all image (instance)
typedef struct s_img
{
	mlx_image_t		*grass[16];
	mlx_image_t		*hill[20];
	mlx_image_t		*dirt[1];
	mlx_image_t		*water[16];
	mlx_image_t		*sand[16];
	mlx_image_t		*deep_dirt[16];
	mlx_image_t		*wood_floor[1];
	mlx_image_t		*wood_wall[20];
	mlx_image_t		*stone_floor[1];
	mlx_image_t		*stone_wall[20];
	mlx_image_t		*player[10];
	mlx_image_t		*selector[1];
	mlx_image_t		*crack[4];
	mlx_image_t		*tree[1];
}					t_img;

typedef struct s_tile_under
{
	char			*name;
	int32_t			id;
	int32_t			depth;
	int32_t			tile_index;
	int32_t			life;
	mlx_image_t		**image;
	bool			solid;
}					t_tile_under;

typedef struct s_tile
{
	char			*name;
	int32_t			id;
	int32_t			depth;
	int32_t			tile_index;
	int32_t			life;
	mlx_image_t		**image;
	bool			solid;
	t_tile_under	under;
}					t_tile;

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
	mlx_t			*mlx;
	t_texture		tex;
	double			delta_time;
	double			current_time;
	int32_t			mouse_id;
	int32_t			p_direction;
	int32_t			arm_range;
	int32_t			state;
	t_img			img;
	t_img			old_img;
	t_tile			***map;
	t_tile			tile_type[20];
	t_vec2			playerGrid;
	t_vec2			player;
	t_vec2			cameraGrid;
	t_vec2			camera;
	t_vec2			offSet;
	t_vec2			mouse;
	t_vec2			mouseGrid;
	t_movement		p_move;
	t_hitbox		p_hitbox;
	t_animation		p_animation;
	t_window		window;
	t_menu			m_start;
}					t_game;

// prototype

// game

t_game				*g(void);

// key function

bool				is_key_pressed(keys_t key);

// draw

void				map_image_to_window(mlx_image_t **img, t_pos2 co,
						bool under);
void				map_image_index_to_window(mlx_image_t *img, t_pos2 co);

// map

t_tile				***allocate_2d_map_array(int32_t rows, int32_t cols);
void				fill_2d_map_array(t_tile ***array, int32_t rows,
						int32_t cols, int32_t c);
void				print_2d_map_array(t_tile ***array, int32_t cols,
						int32_t rows);
void				set_map(int32_t x, int32_t y, int32_t width,
						int32_t height);

// texture

void				init_grass_texture(void);
void				init_hill_texture(void);
void				init_sand_texture(void);
void				init_water_texture(void);
void				init_player_texture(void);
void				init_deep_dirt_texture(void);
void				init_crack_texture(void);
void				init_wood_wall_texture(void);
void				init_stone_wall_texture(void);

// image

void				init_img(t_img *img);
void				del_img(t_img *img);

// tiling

void				auto_tiling(t_vec2 pos, int32_t width, int32_t height);
int32_t				point_distance(t_vec2 bow, t_vec2 target);
void				auto_tiling_corner(mlx_image_t **img, t_pos2 co,
						int32_t id);
bool				place_tile(t_vec2 pos, int32_t id);

// tile type

void				tile_to_under(t_tile *tile, t_tile_under *under);
void				under_to_tile(t_tile_under *under, t_tile *tile);
void				set_grass(void);
void				set_hill(void);
void				set_dirt(void);
void				set_water(void);
void				set_sand(void);
void				set_deep_dirt(void);
void				set_wood_floor(void);
void				set_stone_floor(void);
void				set_wood_wall(void);
void				set_stone_wall(void);
void				set_tree(void);

// string

int					ft_strnum(char **str);
char				ft_itoc(int i);

// collision

bool				tile_collision(int x, int y, int w, int h, int32_t c);

// animation

void				play_animation(t_animation *animation, char **direction);
void				init_player_animation(void);
bool				is_tilable(int32_t id);

// movement

void				movement(t_vec2 *pos, int32_t *dir, t_hitbox hitbox,
						bool is_vertical);
void				player_animation_dir(void);
void				move(void);

// math

int					sign(int nb);
bool				is_even(int nb);

#endif
