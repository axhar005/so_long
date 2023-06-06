#ifndef SO_LONG_H
# define SO_LONG_H

//include

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

//struct

//storage of all texture (png)
typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
}					t_texture;

//storage of all image (instance)
typedef struct s_img
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;

}					t_img;

typedef struct s_game
{
	t_img			img;
	t_texture		tex;
	mlx_t			*mlx;
	int32_t			**grid;
	int32_t			playerX;
	int32_t			playerY;
}					t_game;

//prototype

void				print_2d_int_array(int32_t **array, int32_t rows,
						int32_t cols);
int32_t				**allocate_2d_int_array(int32_t rows, int32_t cols);

#endif