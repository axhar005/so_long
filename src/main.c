#include "../inc/so_long.h"

static t_game	game;

void init_img(t_img *img)
{
		img->floor = mlx_texture_to_image(game.mlx, game.tex.floor);
		img->wall = mlx_texture_to_image(game.mlx, game.tex.wall);
		img->player = mlx_texture_to_image(game.mlx, game.tex.player);
		img->camera = mlx_texture_to_image(game.mlx, game.tex.camera);
}

void del_img(t_img *img)
{
		mlx_delete_image(game.mlx, img->floor);
		mlx_delete_image(game.mlx, img->wall);
		mlx_delete_image(game.mlx, img->player);
		mlx_delete_image(game.mlx, img->camera);
}

void	draw_grid(int32_t posX, int32_t posY)
{
	int32_t	j;
	int32_t	i;

	j = 0;
	while (j < 15)
	{
		i = 0;
		while (i < 21)
		{
			if (game.grid[i + posX][j + posY] == '0')
				mlx_image_to_window(game.mlx, game.img.floor, i * SPRITE_SIZE, j * SPRITE_SIZE);
			else if (game.grid[i + posX][j + posY] == '1')
				mlx_image_to_window(game.mlx, game.img.wall, i * SPRITE_SIZE, j * SPRITE_SIZE);
			i++;
		}
		j++;
	}		
	mlx_image_to_window(game.mlx, game.img.player, 10*SPRITE_SIZE, 7*SPRITE_SIZE);
	mlx_image_to_window(game.mlx, game.img.camera, game.cameraX*SPRITE_SIZE, game.cameraY*SPRITE_SIZE);
}

void draw(void)
{
	static double frame = 0;

	if (frame >= 5)
	{
		del_img(&game.old_img);
		game.old_img = game.img;
		init_img(&game.img);
	 	draw_grid(game.cameraX, game.cameraY);

		frame = 0;
	}
	frame += game.delta_time;
}

void	step(void *param)
{
	mlx_t	*mlx;
	int32_t u;

	u = 0;
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
		
	game.cameraX = (game.playerX / SPRITE_SIZE);
	game.cameraY = (game.playerY / SPRITE_SIZE);
	draw();
	printf("Camera X:%d Y:%d\n", game.cameraX,  game.cameraY);
}

int32_t	main(void)
{
	game.playerX = 10 * SPRITE_SIZE;
	game.playerY = 7 * SPRITE_SIZE;
	game.cameraX = 0;
	game.cameraY = 0;

	//GRID
	game.grid = allocate_2d_char_array(100, 100);
	fill_2d_char_array(game.grid, 100, 100, '0');
	game.grid[0][0] = '1';
	game.grid[0][1] = '1';
	game.grid[1][0] = '1';
	game.grid[5][5] = '1';
	game.grid[10][10] = '1';
	game.grid[15][15] = '1';
	game.grid[20][20] = '1';
	game.grid[30][30] = '1';
	print_2d_char_array(game.grid);


	//MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	game.tex.floor = mlx_load_png("./asset/greenRectangle.png");
	game.tex.player = mlx_load_png("./asset/redRectangle.png");
	game.tex.wall = mlx_load_png("./asset/wall.png");
	game.tex.camera = mlx_load_png("./asset/origin.png");
	init_img(&game.img);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}