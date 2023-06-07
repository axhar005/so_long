#ifndef SO_LONG_H
# define SO_LONG_H

//include

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//struct

# define SPRITE_SIZE 32
# define WIDTH 672
# define HEIGHT 480

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
	double			delta_time;
	char			**grid;
	int32_t			playerX;
	int32_t			playerY;
	int32_t			cameraX;
	int32_t			cameraY;
}					t_game;

//prototype

char				**allocate_2d_char_array(int32_t rows, int32_t cols);
void				print_2d_char_array(char **array);
void				fill_2d_char_array(char **array, int32_t rows, int32_t cols,
						char c);

#endif