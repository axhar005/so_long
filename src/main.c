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
	while (i < w)
	{
		j = 0;
		while (j < h)
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

bool point_distance(t_vec2 bow, t_vec2 target, int32_t distance)
{
	int32_t cal;

	cal = (bow.x - target.x) - (bow.y - target.y);
	if (cal < 0)
		cal *= -1;
	if (cal <= distance)
		return (true);
	return (false);
}

void selector(t_game *game)
{
	if (point_distance(game->playerGrid, game->mouseGrid, game->arm_range))
	{
		ft_printf("zigotou\n");
	}
}

void place_tile(t_vec2 pos, char id)
{
	pos.x = game.cameraGrid.x + ((pos.x+game.offSet.x)/SPRITE_SIZE);
	pos.y = game.cameraGrid.y + ((pos.y+game.offSet.y)/SPRITE_SIZE);
		if ((pos.x >= 0 && pos.x < R_WIDTH) && (pos.y >= 0 && pos.y < R_HEIGHT))
		{
			if (game.grid[pos.x][pos.y]->id != ft_itoc(id))
			{
				game.grid[pos.x][pos.y]->id = ft_itoc(id);
				if (game.grid[pos.x][pos.y]->id == '1' || game.grid[pos.x][pos.y]->id == '3')
					game.grid[pos.x][pos.y]->solid = true;
				if (game.grid[pos.x][pos.y]->id == '0' || game.grid[pos.x][pos.y]->id == '2'|| game.grid[pos.x][pos.y]->id == '4' 
					|| game.grid[pos.x][pos.y]->id == '5' || game.grid[pos.x][pos.y]->id == '6')
					game.grid[pos.x][pos.y]->solid = false;
				auto_tiling(pos.x - 1, pos.y - 1, 3, 3);
			}
		}
}

void	draw_grid(int32_t posX, int32_t posY)
{
	int32_t	j;
	int32_t	i;

	del_img(&game, &game.old_img);
	game.old_img = game.img;
	init_img(&game, &game.img);
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
				else if (game.grid[i + posX][j + posY]->id == '4')
					mlx_image_to_window(game.mlx, game.img.dirt[game.grid[i + posX][j + posY]->tile_index], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY]->id == '5')
					mlx_image_to_window(game.mlx, game.img.plank_floor, (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				else if (game.grid[i + posX][j + posY]->id == '6')
					mlx_image_to_window(game.mlx, game.img.stone_floor, (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
				
				place_tile_corner(i + posX, j + posY, i, j, '1');
			}
			j++;
		}
		i++;
	}
	selector(&game);
	mlx_image_to_window(game.mlx, game.img.player[game.player_animation.index], (C_WIDTH / 2) * SPRITE_SIZE,
			(C_HEIGHT / 2) * SPRITE_SIZE);
}

void	draw(void)
{
	draw_grid(game.cameraGrid.x, game.cameraGrid.y);
}

bool is_key_pressed(t_game *game,  keys_t key)
{
	static keys_t *array;
	int32_t i;

	i = 0;
	if (!array)
		array = ft_calloc(10, sizeof(int32_t));
	if (mlx_is_key_down(game->mlx, key))
	{
		while(i < 10)
		{
			if (array[i] == key)
				return (false);
			i++;
		}
		i = 0;
		while(i < 10)
		{
			if (array[i] == 0)
			{
				array[i] = key;
				return (true);
			}
			i++;
		}
	}
	else
	{
		while(i < 10)
		{
			if (array[i] == key)
			{
				array[i] = 0;
				return (false);
			}
			i++;
		}
	}
	return (false);
}

void	step(void *param)
{
	mlx_t			*mlx;
	int32_t				hspd;
	int32_t				vspd;
	int32_t				spd;
	static double	frame = 0;

	hspd = 0;
	vspd = 0;
	spd = 10;
	mlx = param;
	game.delta_time = game.mlx->delta_time * 30;
	mlx_get_mouse_pos(mlx, &game.mouse.x, &game.mouse.y);
	if (is_key_pressed(&game, MLX_KEY_P))
	{
		game.mouse_id += 1;
		if (game.mouse_id > 6)
			game.mouse_id = 0;
		printf("%s\n", ft_itoa(game.mouse_id));
	}
	if (is_key_pressed(&game, MLX_KEY_O))
	{
		game.mouse_id -= 1;
		if (game.mouse_id < 0)
			game.mouse_id = 6;
		printf("%s\n", ft_itoa(game.mouse_id));
	}
	if (is_key_pressed(&game, MLX_KEY_M))
		print_2d_map_array(game.grid, R_WIDTH, R_HEIGHT);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_RIGHT))
		place_tile(game.mouse, game.mouse_id);
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
				if (tile_collision((game.player.x + game.player_hitbox.left) + hspd, game.player.y
						+ game.player_hitbox.top, SPRITE_SIZE - (game.player_hitbox.right + game.player_hitbox.left),
						SPRITE_SIZE - (game.player_hitbox.bot + game.player_hitbox.top), 's'))
				{
					while (!tile_collision((game.player.x + game.player_hitbox.left) + sign(hspd),
											game.player.y + game.player_hitbox.top,
											SPRITE_SIZE - (game.player_hitbox.right + game.player_hitbox.left),
											SPRITE_SIZE - (game.player_hitbox.bot + game.player_hitbox.top),
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
				if (tile_collision(game.player.x + game.player_hitbox.left, (game.player.y + game.player_hitbox.top)
						+ vspd, SPRITE_SIZE - (game.player_hitbox.right + game.player_hitbox.left), SPRITE_SIZE - (game.player_hitbox.bot + game.player_hitbox.top), 's'))
				{
					while (!tile_collision(game.player.x + game.player_hitbox.left, (game.player.y
								+ game.player_hitbox.top) + sign(vspd), SPRITE_SIZE - (game.player_hitbox.right + game.player_hitbox.left),
							SPRITE_SIZE - (game.player_hitbox.bot + game.player_hitbox.top), 's'))
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
		player_animation_dir(&game);
		draw();
		frame = 0;
	}
	frame += game.delta_time;
	// update player grid pos
	game.playerGrid.x = game.player.x / SPRITE_SIZE;
	game.playerGrid.y = game.player.y / SPRITE_SIZE;
	// update offset
	game.offSet.x = game.player.x % SPRITE_SIZE;
	game.offSet.y = game.player.y % SPRITE_SIZE;
	// update cameraGrid pos
	game.cameraGrid.x = game.playerGrid.x - C_WIDTH / 2;
	game.cameraGrid.y = game.playerGrid.y - C_HEIGHT / 2;
	// update mouseGrid pos
	game.mouseGrid.x = game.cameraGrid.x + ((game.mouse.x+game.offSet.x)/SPRITE_SIZE);
	game.mouseGrid.y = game.cameraGrid.y + ((game.mouse.y+game.offSet.y)/SPRITE_SIZE);
	// printf("X: %d\n", game.mouseGrid.x);
	// printf("Y: %d\n", game.mouseGrid.y);
}

int32_t	main(void)
{
	game.playerGrid.x = 5;
	game.playerGrid.y = 5;
	game.player.x = game.playerGrid.x * SPRITE_SIZE;
	game.player.y = game.playerGrid.y * SPRITE_SIZE;
	game.player_hitbox.top = 16;
	game.player_hitbox.bot = 0;
	game.player_hitbox.left = 12;
	game.player_hitbox.right = 12;
	game.cameraGrid.x = 0;
	game.cameraGrid.y = 0;
	game.offSet.x = 0;
	game.offSet.y = 0;
	game.mouse_id = 0;
	game.arm_range = 3;

	init_player_animation(&game);

	//GRID
	game.grid = allocate_2d_map_array(R_WIDTH, R_HEIGHT);
	fill_2d_map_array(game.grid, R_WIDTH, R_HEIGHT, '0');
	auto_tiling(0, 0, R_WIDTH, R_HEIGHT);
	// print_2d_map_array(game.grid, R_WIDTH, R_HEIGHT);

	//MLX
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	//load texture
	init_grass_texture(game.tex.grass);
	init_sand_texture(game.tex.sand);
	init_wall_texture(game.tex.wall);
	init_water_texture(game.tex.water);
	init_player_texture(game.tex.player);
	init_dirt_texture(game.tex.dirt);
	game.tex.plank_floor = mlx_load_png("./asset/wood/plank_floor.png");
	game.tex.stone_floor = mlx_load_png("./asset/stone/stone_floor.png");
	game.tex.selector = mlx_load_png("./asset/selector.png");

	// init_img(&game);
	mlx_loop_hook(game.mlx, step, game.mlx);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}