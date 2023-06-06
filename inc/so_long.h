#ifndef SO_LONG_H
# define SO_LONG_H

//include

# include "../lib/libft/inc/libft.h"

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

//prototype

#endif