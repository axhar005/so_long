#include "../inc/so_long.h"

static t_game	game;

void init_img(void)
{
	game.img.floor = mlx_texture_to_image(game.mlx, game.tex.floor);
	game.img.wall = mlx_texture_to_image(game.mlx, game.tex.wall);
	game.img.player = mlx_texture_to_image(game.mlx, game.tex.player);
}

void del_img(void)
{
	mlx_delete_image(game.mlx, game.img.floor);
	mlx_delete_image(game.mlx, game.img.wall);
	mlx_delete_image(game.mlx, game.img.player);
}

void	ft_draw_grid(int32_t posX, int32_t posY)
{
	int32_t	j;
	int32_t	i;
	static double frame = 0;

	j = 0;
	if (frame >= 10)
	{
		del_img();
		init_img();
		while (j < 15)
		{
			i = 0;
			while (i < 21)
			{
				if (game.grid[i + posX][j + posY] == '0')
					mlx_image_to_window(game.mlx, game.img.floor, i * 32, j * 32);
				else if (game.grid[i + posX][j + posY] == '1')
					mlx_image_to_window(game.mlx, game.img.wall, i * 32, j * 32);
				i++;
			}
			j++;
		}
		mlx_image_to_window(game.mlx, game.img.player, 0, 0);
		frame = 0;
	}
	frame += game.delta_time;
	printf("%f \n", frame);
	
}

void	step(void *param)
{
	mlx_t	*mlx;

	mlx = param;

	game.delta_time = game.mlx->delta_time * 30;
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
	ft_draw_grid(game.cameraX, game.cameraY);
}

int32_t	main(void)
{
	game.playerX = SPRITE_SIZE * 8;
	game.playerY = SPRITE_SIZE * 8;
	game.cameraX = 0;
	game.cameraY = 0;

	//GRID
	game.grid = allocate_2d_char_array(100, 100);
	fill_2d_char_array(game.grid, 100, 100, '0');
	game.grid[5][5] = '1';
	game.grid[10][7] = '1';
	print_2d_char_array(game.grid);


	//MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	game.tex.floor = mlx_load_png("./asset/greenRectangle.png");
	game.tex.player = mlx_load_png("./asset/redRectangle.png");
	game.tex.wall = mlx_load_png("./asset/wall.png");
	init_img();

	// ft_draw_grid(0, 0);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}