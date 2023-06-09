#ifndef SO_LONG_H
#define SO_LONG_H

// include

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/inc/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// struct

#define SPRITE_SIZE 32
#define WIDTH 672
#define HEIGHT 480
#define C_WIDTH 21
#define C_HEIGHT 15
#define R_WIDTH 100
#define R_HEIGHT 100

// storage of pos x and y
typedef struct s_vec2
{
	int32_t x;
	int32_t y;
} t_vec2;

// storage of all texture (png)
typedef struct s_texture
{
	mlx_texture_t *floor;
	mlx_texture_t *wall;
	mlx_texture_t *player;
	mlx_texture_t *camera;
} t_texture;

// storage of all image (instance)
typedef struct s_img
{
	mlx_image_t *floor;
	mlx_image_t *wall;
	mlx_image_t *player;
	mlx_image_t *camera;

} t_img;

typedef struct s_game
{
	t_img img;
	t_img old_img;
	t_texture tex;
	mlx_t *mlx;
	double delta_time;
	char **grid;
	t_vec2 playerGrid;
	t_vec2 player;
	t_vec2 cameraGrid;
	t_vec2 camera;
	t_vec2 offSet;
} t_game;

// prototype

char **allocate_2d_char_array(int32_t rows, int32_t cols);
void print_2d_char_array(char **array);
void fill_2d_char_array(char **array, int32_t rows, int32_t cols,
						char c);

#endif