#include "../inc/so_long.h"

static t_game	game;

int32_t	calculate_auto_tiling(int32_t x, int32_t y, char c)
{
	int32_t	val;

	val = 0;
	if ((x >= 0 && x < R_WIDTH) && (y >= 0 && y < R_HEIGHT))
	{
		if (y - 1 >= 0 && game.grid[x][y - 1]->id == c)
			val += 1;
		if (x + 1 < R_WIDTH && game.grid[x + 1][y]->id == c)
			val += 10;
		if (y + 1 < R_HEIGHT && game.grid[x][y + 1]->id == c)
			val += 100;
		if (x - 1 >= 0 && game.grid[x - 1][y]->id == c)
			val += 1000;
		return (val);
	}
	return (-1);
}

int32_t	index_auto_tiling(int32_t val)
{
	int32_t	i;
	int		numMappings;

	i = 0;
	int32_t mapping[][2] = {
		{110, 0},
		{1110, 1},
		{1100, 2},
		{111, 3},
		{1111, 4},
		{1101, 5},
		{11, 6},
		{1011, 7},
		{1001, 8},
		{101, 9},
		{1010, 10},
		{0, 11},
		{1, 12},
		{10, 13},
		{100, 14},
		{1000, 15}};
	numMappings = sizeof(mapping) / sizeof(mapping[0]);
	while (i < numMappings)
	{
		if (val == mapping[i][0])
			return (mapping[i][1]);
		i++;
	}
	return (-1);
}

void	auto_tiling(int32_t x, int32_t y, int32_t width, int32_t height)
{
	int32_t i;
	int32_t j;
	int32_t xx;
	int32_t yy;

	i = 0;
	while (i <= width)
	{
		j = 0;
		while (j <= height)
		{
			xx = x + i;
			yy = y + j;
			if ((xx >= 0 && xx < R_WIDTH) && (yy >= 0 && yy < R_HEIGHT))
			{
				game.grid[xx][yy]->tile_index = index_auto_tiling(calculate_auto_tiling(xx, yy, game.grid[xx][yy]->id));
				if (game.grid[xx][yy]->id == '1' || game.grid[xx][yy]->id == '3')
					game.grid[xx][yy]->solid = true;
				if (game.grid[xx][yy]->id == '0' || game.grid[xx][yy]->id == '2')
					game.grid[xx][yy]->solid = false;
			}
			j++;
		}
		i++;
	}
}

void place_tile_corner(int32_t x, int32_t y, int32_t i, int32_t j, char id)
{
	if (game.grid[x][y]->id == id)
	{
		if (game.grid[x][y]->tile_index == 4)
		{
			if (game.grid[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.grid[x][y]->tile_index == 0)
			if (game.grid[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.grid[x][y]->tile_index == 1)
		{
			if (game.grid[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.grid[x][y]->tile_index == 2)
			if (game.grid[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.grid[x][y]->tile_index == 3)
		{
			if (game.grid[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.grid[x][y]->tile_index == 5)
		{
			if (game.grid[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.grid[x][y]->tile_index == 6)
			if (game.grid[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.grid[x][y]->tile_index == 7)
		{
			if (game.grid[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.grid[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.grid[x][y]->tile_index == 8)
			if (game.grid[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
	}
}

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

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (c == 's')
			{
				if (game.grid[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->solid == true)
					return (true);
			}
			else
			{
				if (game.grid[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->id == c)
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

void mouse_click(int32_t mx, int32_t my, char id)
{
	mx = game.cameraGrid.x + ((mx+game.offSet.x)/SPRITE_SIZE);
		my = game.cameraGrid.y + ((my+game.offSet.y)/SPRITE_SIZE);
		if ((mx >= 0 && mx < R_WIDTH) && (my >= 0 && my < R_HEIGHT))
		{
			game.grid[mx][my]->id = id;
			auto_tiling(mx - 1, my - 1, 3, 3);
		}
}

void	init_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 10)
			img->player[i] = mlx_texture_to_image(game.mlx, game.tex.player[i]);
		if (i < 16)
		{
			img->grass[i] = mlx_texture_to_image(game.mlx, game.tex.grass[i]);
			img->sand[i] = mlx_texture_to_image(game.mlx, game.tex.sand[i]);
			img->water[i] = mlx_texture_to_image(game.mlx, game.tex.water[i]);
		}
		if (i < 20)
			img->wall[i] = mlx_texture_to_image(game.mlx, game.tex.wall[i]);
		i++;
	}
}

void	del_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 10)
			mlx_delete_image(game.mlx, img->player[i]);
		if (i < 16)
		{
			mlx_delete_image(game.mlx, img->grass[i]);
			mlx_delete_image(game.mlx, img->sand[i]);
			mlx_delete_image(game.mlx, img->water[i]);
		}
		if (i < 20)
			mlx_delete_image(game.mlx, img->wall[i]);
		i++;
	}
}

void	draw_grid(int32_t posX, int32_t posY)
{
	int32_t	j;
	int32_t	i;

	del_img(&game.old_img);
	game.old_img = game.img;
	init_img(&game.img);
	mlx_image_to_window(game.mlx, game.img.grass[0], -1000, 0);
	i = -1;
	while (i < C_WIDTH + 1)
	{
		j = -1;
		while (j < C_HEIGHT + 1)
		{
			if ((i + posX >= 0 && i + posX < R_WIDTH) && (j + posY >= 0 && j
					+ posY < R_HEIGHT))
			{
				if (game.grid[i + posX][j + posY]->id == '0')
					mlx_image_to_window(game.mlx, game.img.grass[game.grid[i
							+ posX][j + posY]->tile_index], (i * SPRITE_SIZE)
							- game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY]->id == '1')
				{
					mlx_image_to_window(game.mlx, game.img.wall[game.grid[i + posX][j + posY]->tile_index], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
					game.grid[i + posX][j + posY]->solid = true;
				}
				else if (game.grid[i + posX][j + posY]->id == '2')
					mlx_image_to_window(game.mlx, game.img.sand[game.grid[i
							+ posX][j + posY]->tile_index], (i * SPRITE_SIZE)
							- game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY]->id == '3')
				{
					mlx_image_to_window(game.mlx, game.img.water[game.grid[i + posX][j + posY]->tile_index], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
					game.grid[i + posX][j + posY]->solid = true;
				}
				place_tile_corner(i + posX, j + posY, i, j, '1');
			}
			j++;
		}
		i++;
	}
	mlx_image_to_window(game.mlx, game.img.player[4], (C_WIDTH / 2) * SPRITE_SIZE,
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

	int mx = 0;
	int my = 0;
	mlx_get_mouse_pos(mlx, &mx, &my);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_LEFT))
		mouse_click(mx, my, game.mouse_id);
	if (mlx_is_key_down(mlx, MLX_KEY_1))
		game.mouse_id = '1';
	if (mlx_is_key_down(mlx, MLX_KEY_0))
		game.mouse_id = '0';
	if (mlx_is_key_down(mlx, MLX_KEY_2))
		game.mouse_id = '2';
	if (mlx_is_key_down(mlx, MLX_KEY_3))
		game.mouse_id = '3';

	hspd = (mlx_is_key_down(mlx, MLX_KEY_D) - mlx_is_key_down(mlx, MLX_KEY_A))
		* spd;
	vspd = (mlx_is_key_down(mlx, MLX_KEY_S) - mlx_is_key_down(mlx, MLX_KEY_W))
		* spd;
	if (frame >= 1)
	{
		if (hspd != 0)
		{
			if (game.player.x + hspd >= 0 && (game.player.x + SPRITE_SIZE)
				+ hspd <= R_WIDTH * SPRITE_SIZE)
			{
				if (tile_collision((game.player.x + 12) + hspd, game.player.y
						+ 24, SPRITE_SIZE - 24, SPRITE_SIZE - 24, 's'))
				{
					while (!tile_collision((game.player.x + 12) + sign(hspd),
											game.player.y + 24,
											SPRITE_SIZE - 24,
											SPRITE_SIZE - 24,
											's'))
						game.player.x += sign(hspd);
					hspd = 0;
				}
				game.player.x += hspd;
			}
			else
			{
				while (game.player.x + sign(hspd) >= 0 && (game.player.x
						+ SPRITE_SIZE) + sign(hspd) <= R_WIDTH * SPRITE_SIZE)
					game.player.x += sign(hspd);
			}
		}
		if (vspd != 0)
		{
			if (game.player.y + vspd >= 0 && (game.player.y + SPRITE_SIZE)
				+ vspd <= R_HEIGHT * SPRITE_SIZE)
			{
				if (tile_collision(game.player.x + 12, (game.player.y + 24)
						+ vspd, SPRITE_SIZE - 24, SPRITE_SIZE - 24, 's'))
				{
					while (!tile_collision(game.player.x + 12, (game.player.y
								+ 24) + sign(vspd), SPRITE_SIZE - 24,
							SPRITE_SIZE - 24, 's'))
						game.player.y += sign(vspd);
					vspd = 0;
				}
				game.player.y += vspd;
			}
			else
			{
				while (game.player.y + sign(vspd) >= 0 && (game.player.y
						+ SPRITE_SIZE) + sign(vspd) <= R_HEIGHT * SPRITE_SIZE)
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
	game.playerGrid.x = 5;
	game.playerGrid.y = 5;
	game.player.x = game.playerGrid.x * SPRITE_SIZE;
	game.player.y = game.playerGrid.y * SPRITE_SIZE;
	game.cameraGrid.x = 0;
	game.cameraGrid.y = 0;
	game.offSet.x = 0;
	game.offSet.y = 0;
	game.mouse_id = '1';
	// init_player_animation(&game);

	//GRID
	game.grid = allocate_2d_map_array(R_WIDTH, R_HEIGHT);
	fill_2d_map_array(game.grid, R_WIDTH, R_HEIGHT, '0');
	// game.grid[0][0]->id = '1';
	// game.grid[1][0]->id = '1';
	// game.grid[2][0]->id = '1';
	// game.grid[3][0]->id = '1';
	// game.grid[2][1]->id = '1';
	// game.grid[1][1]->id = '1';

	game.grid[0][0]->id = '1';
	game.grid[1][0]->id = '1';
	game.grid[0][1]->id = '1';

	game.grid[8][2]->id = '1';
	game.grid[9][2]->id = '1';
	game.grid[10][2]->id = '1';
	game.grid[8][3]->id = '1';
	game.grid[9][3]->id = '1';
	game.grid[10][3]->id = '1';
	game.grid[8][4]->id = '1';
	game.grid[9][4]->id = '1';
	game.grid[10][4]->id = '1';

	game.grid[2][3]->id = '2';
	game.grid[3][3]->id = '2';
	game.grid[2][4]->id = '2';
	game.grid[2][5]->id = '2';
	game.grid[3][5]->id = '2';
	game.grid[4][5]->id = '2';
	game.grid[4][6]->id = '2';
	game.grid[5][6]->id = '2';
	game.grid[6][7]->id = '2';

	game.grid[3][6]->id = '3';
	game.grid[2][6]->id = '3';
	game.grid[1][6]->id = '3';
	game.grid[1][5]->id = '3';

	auto_tiling(0, 0, R_WIDTH, R_HEIGHT);
	// print_2d_map_array(game.grid);
	// printf("njsad:%d\n",calculate_auto_tiling(4, 4, '0'));

	//MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	init_grass_texture(game.tex.grass);
	init_sand_texture(game.tex.sand);
	init_wall_texture(game.tex.wall);
	init_water_texture(game.tex.water);
	init_player_texture(game.tex.player);


	init_img(&game.img);

	mlx_loop_hook(game.mlx, step, game.mlx);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}