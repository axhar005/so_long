#include "../inc/so_long.h"

static t_game	game;

//
// bool tile_collision(int x1, int y1, int x2, int y2, char c)
// {
// 	if (game.grid[x1/SPRITE_SIZE][y1/SPRITE_SIZE] != c && game.grid[x2/SPRITE_SIZE][y2/SPRITE_SIZE] != c)
// 	{

// 	}
// }

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

	del_img(&game.old_img);
	game.old_img = game.img;
	init_img(&game.img);
	j = -1;
	while (j < C_HEIGHT + 1)
	{
		i = -1;
		while (i < C_WIDTH + 1)
		{
			if ((i + posX >= 0 && i + posX <= R_WIDTH) && (j + posY >= 0 && j + posY <= R_HEIGHT))
			{
				if (game.grid[i + posX][j + posY] == '0')
					mlx_image_to_window(game.mlx, game.img.floor, (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY] == '1')
					mlx_image_to_window(game.mlx, game.img.wall, (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				
			}
			i++;
		}
		j++;
	}
	// mlx_image_to_window(game.mlx, game.img.camera, game.player.x, game.player.y);
	mlx_image_to_window(game.mlx, game.img.player, 10*SPRITE_SIZE, 7*SPRITE_SIZE);
	// mlx_image_to_window(game.mlx, game.img.camera, game.cameraGridX*SPRITE_SIZE, game.cameraGridY*SPRITE_SIZE);
}

void draw(void)
{
	// static double frame = 0;

	// if (frame >= 5)
	// {
	 	draw_grid(game.cameraGrid.x, game.cameraGrid.y);
	// 	frame = 0;
	// }
	// frame += game.delta_time;
}

void	step(void *param)
{
	mlx_t	*mlx;
	int hspd = 0;
	int vspd = 0;
	int spd = 10;
	static double frame = 0;

	mlx = param;
	game.delta_time = game.mlx->delta_time * 30;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	hspd = (mlx_is_key_down(mlx, MLX_KEY_D) - mlx_is_key_down(mlx, MLX_KEY_A)) * spd;
	vspd = (mlx_is_key_down(mlx, MLX_KEY_S) - mlx_is_key_down(mlx, MLX_KEY_W)) * spd;


	if (frame >= 1)
	{
		if (hspd != 0)
		{
			if (game.player.x+hspd >= 0 && game.player.x+hspd <= R_WIDTH*SPRITE_SIZE)
			{
				if (game.grid[(game.player.x+hspd)/SPRITE_SIZE][(game.player.y/SPRITE_SIZE)] != '1')
					game.player.x += hspd;
				else
				{
					if (game.offSet.x != 0)
						game.player.x += hspd/spd;
				}
			}
			else
			{
				if (game.offSet.x != 0)
					game.player.x += hspd/spd;
			}
		}

		if (vspd != 0)
		{
			if (game.player.y+vspd >= 0 && game.player.y+vspd <= R_HEIGHT*SPRITE_SIZE)
			{
				if (game.grid[game.player.x/SPRITE_SIZE][(game.player.y+vspd)/SPRITE_SIZE] != '1')
					game.player.y += vspd;
				else
				{
					if (game.offSet.y != 0)
						game.player.y += vspd/spd;
				}
			}
			else
			{
				if (game.offSet.y != 0)
					game.player.y += vspd/spd;
			}
		}
		frame = 0;
	}
	frame += game.delta_time;
	ft_printf("playerG X:%d Y:%d\n", game.playerGrid.x, game.playerGrid.y);
	ft_printf("player X:%d Y:%d\n", game.player.x, game.player.y);
	ft_printf("offSet X:%d Y:%d\n", game.offSet.x, game.offSet.y);
	ft_printf("camera X:%d Y:%d\n", game.cameraGrid.x, game.cameraGrid.y);

	// update player grid pos
	game.playerGrid.x = game.player.x / SPRITE_SIZE;
	game.playerGrid.y = game.player.y / SPRITE_SIZE;

	// update offset
	game.offSet.x = game.player.x % SPRITE_SIZE;
	game.offSet.y = game.player.y % SPRITE_SIZE;
	
	// update cameraGrid pos
	game.cameraGrid.x = game.playerGrid.x - C_WIDTH/2;
	game.cameraGrid.y = game.playerGrid.y - C_HEIGHT/2;
	draw();
	// printf("Camera X:%d Y:%d\n", game.playerGridX,  game.playerGridY);
}

int32_t	main(void)
{
	game.playerGrid.x = C_WIDTH/2;
	game.playerGrid.y = C_HEIGHT/2;
	game.player.x = game.playerGrid.x * SPRITE_SIZE;
	game.player.y = game.playerGrid.y * SPRITE_SIZE;
	game.cameraGrid.x = 0;
	game.cameraGrid.y = 0;
	game.offSet.x = 0;
	game.offSet.y = 0;

	//GRID
	game.grid = allocate_2d_char_array(R_WIDTH, R_HEIGHT);
	fill_2d_char_array(game.grid, R_WIDTH, R_HEIGHT, '0');
	// game.grid[0][0] = '1';
	game.grid[1][0] = '1';
	game.grid[2][0] = '1';
	game.grid[3][0] = '1';
	game.grid[6][6] = '1';
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