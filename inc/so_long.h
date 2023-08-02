/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 14:28:33 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include

# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft_/inc/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// struct

# define SPRITE_SIZE 64

enum				e_depth
{
	FLOOR,
	WALL
};

enum				e_states
{
	START,
	PAUSE,
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
	TREE,
	PORTAL
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

typedef struct s_parsing
{
	char			**map;
	char			**mapf;
	size_t			height;
	size_t			width;
	size_t			char_e;
	size_t			char_p;
	size_t			char_c;
	size_t			char_0;
	size_t			char_1;
}					t_parsing;

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
	mlx_texture_t	*portal[4];
	mlx_texture_t	*lami[12];
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
	mlx_image_t		*portal[4];
	mlx_image_t		*lami[12];
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

typedef struct s_menu
{
	int32_t			button_slected;
	mlx_image_t		*button[5];
	mlx_texture_t	*tex[5];
}					t_menu;

typedef struct s_animation
{
	int32_t			index;
	size_t			loop;
	double			speed;
	double			clock;
	char			**sheet;
	char			**old_sheet;
	char			**up;
	char			**down;
	char			**left;
	char			**right;

}					t_animation;

typedef struct s_lami
{
	t_vec2			pos;
	t_vec2			grid;
	double			time;
	t_movement		move;
	t_hitbox		hitbox;
	t_animation		animation;
}					t_lami;

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
	size_t			feet_step;
	size_t			cut_tree;
	bool			dev_mod;
	t_img			img;
	t_img			old_img;
	t_tile			***map;
	t_tile			tile_type[20];
	t_vec2			playerGrid;
	t_vec2			old_PlayerGrid;
	t_vec2			player;
	t_vec2			cameraGrid;
	t_vec2			offSet;
	t_vec2			mouse;
	t_vec2			mouseGrid;
	t_movement		p_move;
	t_hitbox		p_hitbox;
	t_animation		p_animation;
	t_window		window;
}					t_game;

// prototype

// static function

t_game				*g(void);
t_parsing			*pars(void);
t_menu				*menu(void);
t_lami				*lami(void);

// key function

bool				is_key_pressed(keys_t key);
bool				mouse_button(int32_t x, int32_t y, int32_t width,
						int32_t height);

// step

void				selector(void);
void				step_menu(void);
void				step_game(void);
void				step_update(void);
void				step_portal(void);
void				step_lami(void);

// draw

void				map_image_to_window(mlx_image_t **img, t_pos2 co,
						bool under);
void				map_image_index_to_window(mlx_image_t *img, t_pos2 co);
void				draw_crack(t_pos2 co);
void				draw_grid(int32_t posX, int32_t posY, t_tile ***map);
void				draw_menu(void);
void				draw_lami(void);
void				draw_feet_count(void);

// map

t_tile				***allocate_2d_map(int32_t rows, int32_t cols);
void				fill_2d_map_array(t_tile ***array, int32_t rows,
						int32_t cols, int32_t c);
void				print_2d_map_array(t_tile ***array, int32_t cols,
						int32_t rows);
void				set_map(int32_t x, int32_t y, int32_t width,
						int32_t height);

// texture

void				init_all_texture(void);
void				del_texture(void);
void				is_null_texture(void);

// image

void				init_img(t_img *img);
void				del_img(t_img *img);
void				init_menu_img(t_menu *menu);
void				del_menu_img(t_menu *menu);

// tiling

void				auto_tiling(t_vec2 pos, int32_t width, int32_t height);
int32_t				point_distance(t_vec2 bow, t_vec2 target);
void				auto_tiling_corner(mlx_image_t **img, t_pos2 co,
						int32_t id);
bool				place_tile(t_vec2 pos, int32_t id);
bool				replace_tile(t_vec2 pos, int32_t id);
bool				is_tilable(int32_t id);

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
void				set_portal(void);

// string

char				ft_itoc(int i);
void				print_2d_char_array(char **array);
char				*ft_del_char(char *str, char c);
size_t				line_count(char **str);
size_t				total_count(char **str);
size_t				char_count_2d(char **str, char c);
size_t				char_count(char *str, char c);
t_vec2				char_find_pos_2d(char **str, char c);

// collision

bool				tile_collision(t_vec2 pos, int w, int h, int32_t c);

// animation

void				play_animation(t_animation *animation, char **direction);
void				init_player_animation(void);
void				init_lami_animation(void);

// movement

void				movement(t_vec2 *pos, int32_t *dir, t_hitbox hitbox,
						bool is_vertical);
void				player_animation_dir(void);
void				move(void);

// utiles

int					sign(int nb);
bool				is_even(int nb);
int					rand_range(int min, int max);

// free

void				**ft_sfree_2d(void **ptr);
void				free_map(t_tile ***map);
void				clean_all(void);

// load read

char				**load_map(char *path);
size_t				count_next_line(int fd);
void				load_in_map(void);

// parsing

void				path_parsing(char *path, char *ext);
void				map_is_rectangle(char **map);
void				map_is_closed(void);
void				map_parsing_element(void);
void				init_parsing(void);
void				flood_fill(char **map, int x, int y);
void				after_flood(void);
void				map_parsing(void);

// init

void				init_window(void);
void				init_menu(void);
void				init_val(void);
void				init_all_tiles(void);
void				init_all(void);

#endif
