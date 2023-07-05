#include "../inc/so_long.h"

bool	tile_collision(int x, int y, int w, int h, int32_t c)
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
				if (g()->map[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->solid == true)
					return (true);
			}
			else
			{
				if (g()->map[(x + i) / SPRITE_SIZE][(y + j)
					/ SPRITE_SIZE]->id == c)
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	place_tile(t_vec2 pos, int32_t id)
{
	if ((pos.x >= 0 && pos.x < R_WIDTH) && (pos.y >= 0 && pos.y < R_HEIGHT))
	{
		*g()->map[pos.x][pos.y] = g()->tile_type[id];
		return (true);
	}
	return (false);
}

void	selector(void)
{
	if (point_distance(g()->playerGrid, g()->mouseGrid) <= g()->arm_range)
	{
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_RIGHT))
			if (place_tile(g()->mouseGrid, g()->mouse_id))
				auto_tiling(g()->mouseGrid.x - 1, g()->mouseGrid.y - 1, 3, 3);
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT)
			&& g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->depth == WALLS)
		{
			g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->life -= 5;
			if (g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->life <= 0)
			{
				place_tile(g()->mouseGrid, DIRT);
				auto_tiling(g()->mouseGrid.x - 1, g()->mouseGrid.y - 1, 3, 3);
			}
		}
		mlx_image_to_window(g()->mlx, g()->img.selector[0], (g()->mouseGrid.x
					- g()->cameraGrid.x) * 64 - g()->offSet.x, (g()->mouseGrid.y
					- g()->cameraGrid.y) * 64 - g()->offSet.y);
	}
}

void	draw_crack(t_pos2 co)
{
	int32_t	life;

	life = g()->map[co.pos1.x][co.pos1.y]->life;
	if (life >= 75 && life < 100)
		map_image_index_to_window(g()->img.crack[0], co);
	else if (life >= 50 && life < 75)
		map_image_index_to_window(g()->img.crack[1], co);
	else if (life >= 25 && life < 50)
		map_image_index_to_window(g()->img.crack[2], co);
	else if (life < 25)
		map_image_index_to_window(g()->img.crack[3], co);
}

void	draw_grid(int32_t posX, int32_t posY)
{
	t_pos2	co;

	del_img(&g()->old_img);
	g()->old_img = g()->img;
	init_img(&g()->img);
	mlx_image_to_window(g()->mlx, g()->img.grass[0], -1000, 0);
	co.pos2.x = -1;
	while (co.pos2.x < C_WIDTH + 1)
	{
		co.pos2.y = -1;
		while (co.pos2.y < C_HEIGHT + 1)
		{
			co.pos1.x = co.pos2.x + posX;
			co.pos1.y = co.pos2.y + posY;
			if ((co.pos2.x + posX >= 0 && co.pos2.x + posX < R_WIDTH)
				&& (co.pos2.y + posY >= 0 && co.pos2.y + posY < R_HEIGHT))
			{
				if (g()->map[co.pos2.x + posX][co.pos2.y + posY]->id == GRASS)
					map_image_to_window(g()->img.grass, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == HILL)
					map_image_to_window(g()->img.hill, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == DIRT)
					map_image_to_window(g()->img.dirt, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == WATER)
					map_image_to_window(g()->img.water, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == SAND)
					map_image_to_window(g()->img.sand, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == DEEP_DIRT)
					map_image_to_window(g()->img.deep_dirt, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == WOOD_FLOOR)
					map_image_to_window(g()->img.wood_floor, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == STONE_FLOOR)
					map_image_to_window(g()->img.stone_floor, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == WOOD_WALL)
					map_image_to_window(g()->img.wood_wall, co);
				else if (g()->map[co.pos2.x + posX][co.pos2.y
						+ posY]->id == STONE_WALL)
					map_image_to_window(g()->img.stone_wall, co);
				auto_tilling_corner(g()->img.hill, co, HILL);
				auto_tilling_corner(g()->img.wood_wall, co, WOOD_WALL);
				auto_tilling_corner(g()->img.stone_wall, co, STONE_WALL);
				draw_crack(co);
			}
			co.pos2.y++;
		}
		co.pos2.x++;
	}
	selector();
	mlx_image_to_window(g()->mlx, g()->img.player[g()->player_animation.index],
			(C_WIDTH / 2) * SPRITE_SIZE, (C_HEIGHT / 2) * SPRITE_SIZE);
}

void	draw(void)
{
	draw_grid(g()->cameraGrid.x, g()->cameraGrid.y);
}

bool	is_key_pressed(keys_t key)
{
	static keys_t	*array;
	int32_t			i;

	i = 0;
	if (!array)
		array = ft_calloc(10, sizeof(int32_t));
	if (mlx_is_key_down(g()->mlx, key))
	{
		while (i < 10)
		{
			if (array[i] == key)
				return (false);
			i++;
		}
		i = 0;
		while (i < 10)
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
		while (i < 10)
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
	int32_t			hspd;
	int32_t			vspd;
	int32_t			spd;
	static double	frame = 0;
	t_vec2			origin;

	hspd = 0;
	vspd = 0;
	spd = 10;
	mlx = param;
	g()->delta_time = g()->mlx->delta_time * 30;
	mlx_get_mouse_pos(mlx, &g()->mouse.x, &g()->mouse.y);
	if (is_key_pressed(MLX_KEY_P))
	{
		g()->mouse_id += 1;
		if (g()->mouse_id > 9)
			g()->mouse_id = 0;
		printf("%s\n", ft_itoa(g()->mouse_id));
	}
	if (is_key_pressed(MLX_KEY_O))
	{
		g()->mouse_id -= 1;
		if (g()->mouse_id < 0)
			g()->mouse_id = 9;
		printf("%s\n", ft_itoa(g()->mouse_id));
	}
	if (is_key_pressed(MLX_KEY_M))
		print_2d_map_array(g()->map, R_WIDTH, R_HEIGHT);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	hspd = (mlx_is_key_down(mlx, MLX_KEY_D) - mlx_is_key_down(mlx, MLX_KEY_A))
		* spd;
	vspd = (mlx_is_key_down(mlx, MLX_KEY_S) - mlx_is_key_down(mlx, MLX_KEY_W))
		* spd;
	origin.x = g()->player.x - 32;
	origin.y = g()->player.y - 32;
	if (frame >= 1)
	{
		movement(&origin, &hspd, g()->player_hitbox, false);
		movement(&origin, &vspd, g()->player_hitbox, true);
		player_animation_dir();
		draw();
		frame = 0;
	}
	frame += g()->delta_time;
	//uptade time
	g()->current_time += g()->mlx->delta_time;
	//update player origin
	g()->player.x = origin.x + 32;
	g()->player.y = origin.y + 32;
	// update player grid pos
	g()->playerGrid.x = g()->player.x / SPRITE_SIZE;
	g()->playerGrid.y = g()->player.y / SPRITE_SIZE;
	// update offset
	g()->offSet.x = (g()->player.x % SPRITE_SIZE) - 32;
	g()->offSet.y = (g()->player.y % SPRITE_SIZE) - 32;
	// update cameraGrid pos
	g()->cameraGrid.x = g()->playerGrid.x - C_WIDTH / 2;
	g()->cameraGrid.y = g()->playerGrid.y - C_HEIGHT / 2;
	g()->mouseGrid.x = g()->cameraGrid.x + ((g()->mouse.x + g()->offSet.x)
			/ SPRITE_SIZE);
	g()->mouseGrid.y = g()->cameraGrid.y + ((g()->mouse.y + g()->offSet.y)
			/ SPRITE_SIZE);
}

// bool	broke_tile(void)
// {

// }

void	set_map(int32_t x, int32_t y, int32_t width, int32_t height)
{
	int32_t	i;
	int32_t	j;
	t_vec2	map;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			map.x = x + i;
			map.y = y + j;
			if ((map.x >= 0 && map.x < R_WIDTH) && (map.y >= 0
					&& map.y < R_HEIGHT))
				place_tile(map, g()->map[map.x][map.y]->id);
			j++;
		}
		i++;
	}
}

int32_t	main(void)
{
	g()->playerGrid.x = 5;
	g()->playerGrid.y = 5;
	g()->player.x = g()->playerGrid.x * SPRITE_SIZE;
	g()->player.y = g()->playerGrid.y * SPRITE_SIZE;
	g()->player_hitbox.top = 16;
	g()->player_hitbox.bot = 0;
	g()->player_hitbox.left = 12;
	g()->player_hitbox.right = 12;
	g()->cameraGrid.x = 0;
	g()->cameraGrid.y = 0;
	g()->offSet.x = 0;
	g()->offSet.y = 0;
	g()->mouse_id = 0;
	g()->arm_range = 20;
	g()->current_time = 0;

	init_player_animation();

	//set tile type
	set_grass(&g()->tile_type[0]);
	set_hill(&g()->tile_type[1]);
	set_dirt(&g()->tile_type[2]);
	set_water(&g()->tile_type[3]);
	set_sand(&g()->tile_type[4]);
	set_deep_dirt(&g()->tile_type[5]);
	set_wood_floor(&g()->tile_type[6]);
	set_stone_floor(&g()->tile_type[7]);
	set_wood_wall(&g()->tile_type[8]);
	set_stone_wall(&g()->tile_type[9]);

	//GRID
	g()->map = allocate_2d_map_array(R_WIDTH, R_HEIGHT);
	set_map(0, 0, R_WIDTH, R_HEIGHT);
	auto_tiling(0, 0, R_WIDTH, R_HEIGHT);

	//MLX
	g()->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);

	//load texture
	init_grass_texture();
	init_sand_texture();
	init_hill_texture();
	init_water_texture();
	init_player_texture();
	init_deep_dirt_texture();
	init_crack_texture();
	init_wood_wall_texture();
	init_stone_wall_texture();
	g()->tex.wood_floor[0] = mlx_load_png("./asset/wood/wood_floor/wood_floor.png");
	g()->tex.stone_floor[0] = mlx_load_png("./asset/stone/stone_floor/stone_floor.png");
	g()->tex.selector[0] = mlx_load_png("./asset/selector.png");
	g()->tex.dirt[0] = mlx_load_png("./asset/dirt/dirt_0.png");

	mlx_loop_hook(g()->mlx, step, g()->mlx);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}