#include "../inc/so_long.h"

static t_game	game;

int	sign(int nb)
{
	return ((nb > 0) - (nb < 0));
}

bool	is_even(int nb)
{
	if (nb % 2 == 0)
		return (true);
	return (false);
}

bool	tile_collision(int x, int y, int w, int h, char c)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			if (game.grid[(x + i) / SPRITE_SIZE][(y + j) / SPRITE_SIZE]->id == c)
				return (true);
			i++;
		}
		j++;
	}
	return (false);
}

void	init_img(t_img *img)
{
	img->floor = mlx_texture_to_image(game.mlx, game.tex.floor[4]);
	img->wall = mlx_texture_to_image(game.mlx, game.tex.wall);
	img->player = mlx_texture_to_image(game.mlx, game.tex.player[0]);
}

void	del_img(t_img *img)
{
	mlx_delete_image(game.mlx, img->floor);
	mlx_delete_image(game.mlx, img->wall);
	mlx_delete_image(game.mlx, img->player);
}

void	draw_grid(int32_t posX, int32_t posY)
{
	int32_t	j;
	int32_t	i;

	del_img(&game.old_img);
	game.old_img = game.img;
	init_img(&game.img);
	mlx_image_to_window(game.mlx, game.img.floor, -1000, 0);
	j = -1;
	while (j < C_HEIGHT + 1)
	{
		i = -1;
		while (i < C_WIDTH + 1)
		{
			if ((i + posX >= 0 && i + posX <= R_WIDTH) && (j + posY >= 0 && j
					+ posY <= R_HEIGHT))
			{
				if (game.grid[i + posX][j + posY]->id == '0')
					mlx_image_to_window(game.mlx, game.img.floor, (i
								* SPRITE_SIZE) - game.offSet.x, (j
								* SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY]->id == '1')
					mlx_image_to_window(game.mlx, game.img.wall, (i
								* SPRITE_SIZE) - game.offSet.x, (j
								* SPRITE_SIZE) - game.offSet.y);
			}
			i++;
		}
		j++;
	}
	mlx_image_to_window(game.mlx, game.img.player, (C_WIDTH / 2) * SPRITE_SIZE,
			(C_HEIGHT / 2) * SPRITE_SIZE);
}

void	draw(void)
{
	draw_grid(game.cameraGrid.x, game.cameraGrid.y);
}

void	step(void *param)
{
	mlx_t			*mlx;
	int				hspd;
	int				vspd;
	int				spd;
	static double	frame = 0;

	hspd = 0;
	vspd = 0;
	spd = 10;
	mlx = param;
	game.delta_time = game.mlx->delta_time * 30;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	hspd = (mlx_is_key_down(mlx, MLX_KEY_D) - mlx_is_key_down(mlx, MLX_KEY_A))
		* spd;
	vspd = (mlx_is_key_down(mlx, MLX_KEY_S) - mlx_is_key_down(mlx, MLX_KEY_W))
		* spd;
	if (frame >= 1)
	{
		if (hspd != 0)
		{
			if (game.player.x + hspd >= 0 && game.player.x + hspd <= R_WIDTH
				* SPRITE_SIZE)
			{
				if (tile_collision((game.player.x + 12) + hspd, game.player.y
						+ 24, SPRITE_SIZE - 24, SPRITE_SIZE - 24, '1'))
				{
					while (!tile_collision((game.player.x + 12) + sign(hspd),
							game.player.y + 24, SPRITE_SIZE - 24, SPRITE_SIZE
							- 24, '1'))
						game.player.x += sign(hspd);
					hspd = 0;
				}
				game.player.x += hspd;
			}
			else
			{
				while (game.player.x + sign(hspd) >= 0 && game.player.x
					+ sign(hspd) <= R_WIDTH * SPRITE_SIZE)
					game.player.x += sign(hspd);
			}
		}
		if (vspd != 0)
		{
			if (game.player.y + vspd >= 0 && game.player.y + vspd <= R_HEIGHT
				* SPRITE_SIZE)
			{
				if (tile_collision(game.player.x + 12, (game.player.y + 24)
						+ vspd, SPRITE_SIZE - 24, SPRITE_SIZE - 24, '1'))
				{
					while (!tile_collision(game.player.x + 12, (game.player.y
								+ 24) + sign(vspd), SPRITE_SIZE - 24,
							SPRITE_SIZE - 24, '1'))
						game.player.y += sign(vspd);
					vspd = 0;
				}
				game.player.y += vspd;
			}
			else
			{
				while (game.player.y + sign(vspd) >= 0 && game.player.y
					+ sign(vspd) <= R_HEIGHT * SPRITE_SIZE)
					game.player.y += sign(vspd);
			}
		}
		frame = 0;
	}
	frame += game.delta_time;
	// ft_printf("----------------------------\n");
	// ft_printf("playerG X:%d Y:%d\n", game.playerGrid.x, game.playerGrid.y);
	// ft_printf("player X:%d Y:%d\n", game.player.x, game.player.y);
	// ft_printf("offSet X:%d Y:%d\n", game.offSet.x, game.offSet.y);
	// ft_printf("camera X:%d Y:%d\n", game.cameraGrid.x, game.cameraGrid.y);
	// ft_printf("----------------------------\n");
	// update player grid pos
	game.playerGrid.x = game.player.x / SPRITE_SIZE;
	game.playerGrid.y = game.player.y / SPRITE_SIZE;
	// update offset
	game.offSet.x = game.player.x % SPRITE_SIZE;
	game.offSet.y = game.player.y % SPRITE_SIZE;
	// update cameraGrid pos
	game.cameraGrid.x = game.playerGrid.x - C_WIDTH / 2;
	game.cameraGrid.y = game.playerGrid.y - C_HEIGHT / 2;
	draw();
}

int32_t	main(void)
{
	game.playerGrid.x = C_WIDTH / 2;
	game.playerGrid.y = C_HEIGHT / 2;
	game.player.x = game.playerGrid.x * SPRITE_SIZE;
	game.player.y = game.playerGrid.y * SPRITE_SIZE;
	game.cameraGrid.x = 0;
	game.cameraGrid.y = 0;
	game.offSet.x = 0;
	game.offSet.y = 0;

	//GRID
	game.grid = allocate_2d_map_array(R_WIDTH, R_HEIGHT);
	fill_2d_map_array(game.grid, R_WIDTH, R_HEIGHT, '0');
	game.grid[1][0]->id = '1';
	game.grid[2][0]->id = '1';
	game.grid[3][0]->id = '1';
	game.grid[6][6]->id = '1';
	game.grid[8][6]->id = '1';
	game.grid[8][5]->id = '1';
	game.grid[10][5]->id = '1';
	game.grid[12][5]->id = '1';
	print_2d_map_array(game.grid);

	//MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	game.tex.floor[0] = mlx_load_png("./asset/grass/grass_0.png");
	game.tex.floor[1] = mlx_load_png("./asset/grass/grass_1.png");
	game.tex.floor[2] = mlx_load_png("./asset/grass/grass_2.png");
	game.tex.floor[3] = mlx_load_png("./asset/grass/grass_3.png");
	game.tex.floor[4] = mlx_load_png("./asset/grass/grass_4.png");
	game.tex.floor[5] = mlx_load_png("./asset/grass/grass_5.png");
	game.tex.floor[6] = mlx_load_png("./asset/grass/grass_6.png");
	game.tex.floor[7] = mlx_load_png("./asset/grass/grass_7.png");
	game.tex.floor[8] = mlx_load_png("./asset/grass/grass_8.png");
	game.tex.floor[9] = mlx_load_png("./asset/grass/grass_9.png");
	game.tex.floor[10] = mlx_load_png("./asset/grass/grass_10.png");
	game.tex.floor[11] = mlx_load_png("./asset/grass/grass_11.png");
	game.tex.floor[12] = mlx_load_png("./asset/grass/grass_12.png");
	game.tex.floor[13] = mlx_load_png("./asset/grass/grass_13.png");
	game.tex.floor[14] = mlx_load_png("./asset/grass/grass_14.png");
	game.tex.floor[15] = mlx_load_png("./asset/grass/grass_15.png");

	game.tex.player[0] = mlx_load_png("./asset/player/player_down.png");

	game.tex.wall = mlx_load_png("./asset/wall/wall_11.png");
	init_img(&game.img);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}