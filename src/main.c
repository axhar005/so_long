#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../inc/so_long.h"


#define WIDTH 512
#define HEIGHT 512

static t_img img;


void ft_draw_grid(void *param)
{
	mlx_t* mlx;
	mlx = param;
	static double time = 0;
	time += mlx->delta_time;
	printf("%f\n", time);
	if (time >= 1)
		time = 0;
	if (time == 0)
	{
		//mlx_delete_image(mlx, img.floor);
		mlx_image_to_window(mlx, img.floor, 0*32, 0*32);
		mlx_image_to_window(mlx, img.floor, 2*32, 2*32);
		mlx_image_to_window(mlx, img.player, 4*32, 2*32);
		time  = 0;
	}
	//ft_printf("%d\n", img.floor->count);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	//printf("%f\n", mlx->delta_time);

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		img.player->instances[0].y -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		img.player->instances[0].y += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		img.player->instances[0].x -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		img.player->instances[0].x += 1;
}



int32_t main(void)
{
	mlx_t* mlx;
	t_texture texture;
	//int map[5][5];


	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	texture.floor = mlx_load_png("./asset/greenRectangle.png");
	texture.player = mlx_load_png("./asset/redRectangle.png");

	img.floor = mlx_texture_to_image(mlx, texture.floor);
	img.player = mlx_texture_to_image(mlx, texture.player);

	mlx_loop_hook(mlx, ft_draw_grid, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}