#include "../inc/so_long.h"


#define WIDTH 512
#define HEIGHT 512

static t_game game;


// void ft_draw_grid(int32_t posX, int32_t posY)
// {
// 	int32_t j;
// 	int32_t i;

// 	j = 0;
// 	while (j <= 9-posY)
// 	{
// 		i = 0;
// 		while (i <= 9-posX)
// 		{
// 			if (game.grid[posX*i][posY*j] == 0)
// 				mlx_image_to_window(game.mlx, game.img.floor, i*32, j*32);
// 			// else if (game.grid[posX*i][posY*j] == 1)
// 			// 	mlx_image_to_window(game.mlx, game.img.player, i*32, j*32);
// 			i++;
// 		}
// 		j++;
// 	}
// 	ft_printf("%d\n", game.img.floor->count);
	
// 	// mlx_image_to_window(mlx, game.img.floor, 0*32, 0*32);
// 	// mlx_image_to_window(mlx, game.img.floor, 2*32, 2*32);
// 	// mlx_image_to_window(mlx, game.img.player, 4*32, 2*32);
// }

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
	game.grid = allocate_2d_int_array(10, 10);

	// game.grid[1][1] = 1;
	// game.grid[2][2] = 1;
	//game.grid[8][8] = 1;
	print_2d_int_array(game.grid, 5, 5);
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	game.tex.floor = mlx_load_png("./asset/greenRectangle.png");
	game.tex.player = mlx_load_png("./asset/redRectangle.png");

	game.img.floor = mlx_texture_to_image(game.mlx, game.tex.floor);
	game.img.player = mlx_texture_to_image(game.mlx, game.tex.player);

	// ft_draw_grid(5, 5);
	//mlx_image_to_window(game.mlx, game.img.player, 0*32, 0*32);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}