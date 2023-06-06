#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../inc/so_long.h"


#define WIDTH 512
#define HEIGHT 512

static t_game game;


void ft_draw_grid(int posX, int posY)
{
	(void)posX;
	(void)posY;
	int j;
	int i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			mlx_image_to_window(game.mlx, game.img.floor, i*32, j*32);
			i++;
		}
		j++;
	}
	
	// mlx_image_to_window(mlx, game.img.floor, 0*32, 0*32);
	// mlx_image_to_window(mlx, game.img.floor, 2*32, 2*32);
	// mlx_image_to_window(mlx, game.img.player, 4*32, 2*32);
}

void step(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		game.playerY -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		game.playerY += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		game.playerX -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		game.playerX += 1;

	if (game.img.player->count > 0)
	{
		game.img.player->instances[0].x = game.playerX;
		game.img.player->instances[0].y = game.playerY;
	}
}



int32_t main(void)
{
	game.playerX = 32;
	game.playerY = 32;

	// game.grid[1][1] = 1;
	// game.grid[2][2] = 1;
	// game.grid[3][3] = 1;

	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	game.tex.floor = mlx_load_png("./asset/greenRectangle.png");
	game.tex.player = mlx_load_png("./asset/redRectangle.png");

	game.img.floor = mlx_texture_to_image(game.mlx, game.tex.floor);
	game.img.player = mlx_texture_to_image(game.mlx, game.tex.player);

	//mlx_image_to_window(game.mlx, game.img.floor, 0*32, 0*32);
	mlx_image_to_window(game.mlx, game.img.player, 0*32, 0*32);
	// game.img.player->instances[0].z = 20;
	// mlx_set_instance_depth(game.img.player->instances, 100);
	ft_draw_grid(0, 0);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}