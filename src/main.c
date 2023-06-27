#include "../inc/so_long.h"

static t_game	game;

bool	is_tilable(char id)
{
	if (id == '0' || id == '1' || id == '3' || id == '4' || id == '5')
		return (true);
	return (false);
}

int32_t	calculate_auto_tiling(int32_t x, int32_t y, char c)
{
	int32_t	val;

	val = 0;
	if ((x >= 0 && x < R_WIDTH) && (y >= 0 && y < R_HEIGHT))
	{
		if (y - 1 >= 0 && game.map[x][y - 1]->id == c)
			val += 1;
		if (x + 1 < R_WIDTH && game.map[x + 1][y]->id == c)
			val += 10;
		if (y + 1 < R_HEIGHT && game.map[x][y + 1]->id == c)
			val += 100;
		if (x - 1 >= 0 && game.map[x - 1][y]->id == c)
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
				if (is_tilable(game.map[xx][yy]->id))
					game.map[xx][yy]->tile_index = index_auto_tiling(calculate_auto_tiling(xx, yy, game.map[xx][yy]->id));
				else
					game.map[xx][yy]->tile_index = 0;
			}
			j++;
		}
		i++;
	}
}

void place_tile_corner(int32_t x, int32_t y, int32_t i, int32_t j, char id)
{
	if (game.map[x][y]->id == id)
	{
		if (game.map[x][y]->tile_index == 4)
		{
			if (game.map[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.map[x][y]->tile_index == 0)
			if (game.map[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.map[x][y]->tile_index == 1)
		{
			if (game.map[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.map[x][y]->tile_index == 2)
			if (game.map[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.map[x][y]->tile_index == 3)
		{
			if (game.map[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x+1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[19], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.map[x][y]->tile_index == 5)
		{
			if (game.map[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x-1][y+1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[18], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.map[x][y]->tile_index == 6)
			if (game.map[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		if (game.map[x][y]->tile_index == 7)
		{
			if (game.map[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
			if (game.map[x+1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[17], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
		}
		if (game.map[x][y]->tile_index == 8)
			if (game.map[x-1][y-1]->id != id)
				mlx_image_to_window(game.mlx, game.img.wall[16], (i * SPRITE_SIZE) - game.offSet.x, (j * SPRITE_SIZE) - game.offSet.y);
	}
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
				if (game.map[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->solid == true)
					return (true);
			}
			else
			{
				if (game.map[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->id == c)
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

int32_t point_distance(t_vec2 bow, t_vec2 target)
{
	int32_t cal1;
	int32_t cal2;
	int32_t res;

	cal1 = (bow.x - target.x);
	cal2 = (bow.y - target.y);
	if (cal1 < 0)
		cal1 *= -1;
	if (cal2 < 0)
		cal2 *= -1;
	res = cal1 + cal2;
	if (res < 0)
		res *= -1;
	return (res);
}

// void break_tile(t_vec2 pos, char id)
// {
// 	if ((pos.x >= 0 && pos.x < R_WIDTH) && (pos.y >= 0 && pos.y < R_HEIGHT))
// 	{

// 	}
// }

void place_tile(t_vec2 pos, char id)
{
	if ((pos.x >= 0 && pos.x < R_WIDTH) && (pos.y >= 0 && pos.y < R_HEIGHT))
	{
		if (game.map[pos.x][pos.y]->id != ft_itoc(id))
		{
			game.map[pos.x][pos.y]->id = ft_itoc(id);
			if (game.map[pos.x][pos.y]->id == '1' || game.map[pos.x][pos.y]->id == '3')
				game.map[pos.x][pos.y]->solid = true;
			if (game.map[pos.x][pos.y]->id == '0' || game.map[pos.x][pos.y]->id == '2'|| game.map[pos.x][pos.y]->id == '4' 
				|| game.map[pos.x][pos.y]->id == '5' || game.map[pos.x][pos.y]->id == '6')
				game.map[pos.x][pos.y]->solid = false;
			auto_tiling(pos.x - 1, pos.y - 1, 3, 3);
		}
	}
}

void	selector(t_game *game)
{
	if (point_distance(game->playerGrid, game->mouseGrid) <= game->arm_range)
	{
		if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_RIGHT))
			place_tile(game->mouseGrid, game->mouse_id);
		mlx_image_to_window(game->mlx, game->img.selector[0], (game->mouseGrid.x - game->cameraGrid.x) * 64 - game->offSet.x, (game->mouseGrid.y - game->cameraGrid.y) * 64 - game->offSet.y);
	}
}

void	map_image_to_window(t_game *g, mlx_image_t **img, t_pos2 co, bool solid)
{
	mlx_image_to_window(g->mlx, img[g->map[co.pos1.x][co.pos1.y]->tile_index], 
		(co.pos2.x * SPRITE_SIZE) - g->offSet.x, (co.pos2.y * SPRITE_SIZE) - g->offSet.y);
	g->map[co.pos1.x][co.pos1.y]->solid = solid;
}

void	draw_grid(int32_t posX, int32_t posY)
{
	t_pos2 co;

	del_img(&game, &game.old_img);
	game.old_img = game.img;
	init_img(&game, &game.img);
	mlx_image_to_window(game.mlx, game.img.grass[0], -1000, 0);
	co.pos2.x = -1;
	while (co.pos2.x < C_WIDTH + 1)
	{
		co.pos2.y = -1;
		while (co.pos2.y < C_HEIGHT + 1)
		{
			co.pos1.x = co.pos2.x + posX;
			co.pos1.y = co.pos2.y + posY;
			if ((co.pos2.x+ posX >= 0 && co.pos2.x+ posX < R_WIDTH) && (co.pos2.y + posY >= 0 && co.pos2.y
					+ posY < R_HEIGHT))
			{
				if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '0')
					map_image_to_window(&game, game.img.grass, co, false);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '1')
					map_image_to_window(&game, game.img.wall, co, true);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '2')
					map_image_to_window(&game, game.img.dirt, co, false);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '3')
					map_image_to_window(&game, game.img.water, co, true);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '4')
					map_image_to_window(&game, game.img.sand, co, false);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '5')
					map_image_to_window(&game, game.img.deep_dirt, co, true);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '6')
					map_image_to_window(&game, game.img.plank_floor, co, false);
				else if (game.map[co.pos2.x + posX][co.pos2.y + posY]->id == '7')
					map_image_to_window(&game, game.img.stone_floor, co, false);
					
				place_tile_corner(co.pos2.x + posX, co.pos2.y + posY, co.pos2.x, co.pos2.y, '1');
			}
			co.pos2.y++;
		}
		co.pos2.x++;
	}
	selector(&game);
	mlx_image_to_window(game.mlx, game.img.player[game.player_animation.index], (C_WIDTH / 2) * SPRITE_SIZE - 32,
			(C_HEIGHT / 2) * SPRITE_SIZE - 32);
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
	t_vec2 origin;
	origin.x = game.player.x - 32;
	origin.y = game.player.y - 32;
	mlx_get_mouse_pos(mlx, &game.mouse.x, &game.mouse.y);
	if (is_key_pressed(&game, MLX_KEY_P))
	{
		game.mouse_id += 1;
		if (game.mouse_id > 7)
			game.mouse_id = 0;
		printf("%s\n", ft_itoa(game.mouse_id));
	}
	if (is_key_pressed(&game, MLX_KEY_O))
	{
		game.mouse_id -= 1;
		if (game.mouse_id < 0)
			game.mouse_id = 7;
		printf("%s\n", ft_itoa(game.mouse_id));
	}
	if (is_key_pressed(&game, MLX_KEY_M))
		print_2d_map_array(game.map, R_WIDTH, R_HEIGHT);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	hspd = (mlx_is_key_down(mlx, MLX_KEY_D) - mlx_is_key_down(mlx, MLX_KEY_A))
		* spd;
	vspd = (mlx_is_key_down(mlx, MLX_KEY_S) - mlx_is_key_down(mlx, MLX_KEY_W))
		* spd;
	if (frame >= 1)
	{
			movement(&origin, &hspd, game.player_hitbox, false);
			movement(&origin, &vspd, game.player_hitbox, true);
		
		player_animation_dir(&game);
		draw();
		frame = 0;
	}
	frame += game.delta_time;

	game.player.x = origin.x + 32;
	game.player.y = origin.y + 32;
	// update player grid pos
	game.playerGrid.x = game.player.x / SPRITE_SIZE;
	game.playerGrid.y = game.player.y / SPRITE_SIZE;
	// update offset
	game.offSet.x = game.player.x % SPRITE_SIZE;
	game.offSet.y = game.player.y % SPRITE_SIZE;
	// update cameraGrid pos
	game.cameraGrid.x = game.playerGrid.x - C_WIDTH / 2;
	game.cameraGrid.y = game.playerGrid.y - C_HEIGHT / 2;

	game.mouseGrid.x = game.cameraGrid.x + ((game.mouse.x + game.offSet.x)/SPRITE_SIZE);
	game.mouseGrid.y = game.cameraGrid.y + ((game.mouse.y + game.offSet.y)/SPRITE_SIZE);
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
	game.arm_range = 2;

	init_player_animation(&game);

	//GRID
	game.map = allocate_2d_map_array(R_WIDTH, R_HEIGHT);
	fill_2d_map_array(game.map, R_WIDTH, R_HEIGHT, '0');
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
	init_deep_dirt_texture(game.tex.deep_dirt);
	game.tex.plank_floor[0] = mlx_load_png("./asset/wood/plank_floor.png");
	game.tex.stone_floor[0] = mlx_load_png("./asset/stone/stone_floor.png");
	game.tex.selector[0] = mlx_load_png("./asset/selector.png");
	game.tex.dirt[0] = mlx_load_png("./asset/dirt/dirt_0.png");

	// init_img(&game);
	mlx_loop_hook(game.mlx, step, game.mlx);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}