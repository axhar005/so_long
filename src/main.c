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

void	selector(void)
{
	if (point_distance(g()->playerGrid, g()->mouseGrid) <= g()->arm_range)
	{
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_RIGHT))
			if (place_tile(g()->mouseGrid, g()->mouse_id))
				auto_tiling(g()->mouseGrid.x - 1, g()->mouseGrid.y - 1, 3, 3);
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT)
			&& g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->depth == WALL)
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
	while (co.pos2.x < g()->window.c_width + 1)
	{
		co.pos2.y = -1;
		while (co.pos2.y < g()->window.c_height + 1)
		{
			co.pos1.x = co.pos2.x + posX;
			co.pos1.y = co.pos2.y + posY;
			if ((co.pos1.x >= 0 && co.pos1.x < g()->window.r_width)
				&& (co.pos1.y >= 0 && co.pos1.y < g()->window.r_height))
			{
				map_image_to_window(g()->map[co.pos1.x][co.pos1.y]->image, co);
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
	mlx_image_to_window(g()->mlx, g()->img.player[g()->p_animation.index],
			(C_WIDTH / 2) * SPRITE_SIZE, (C_HEIGHT / 2) * SPRITE_SIZE);
}

void	draw(void)
{
	if (g()->state == START)
	{
		
	}
	if (g()->state == GAME)
	{
		draw_grid(g()->cameraGrid.x, g()->cameraGrid.y);
	}
}

void	step(void *param)
{
	static double	frame = 0;

	g()->p_move.spd = 10;
	(void)param;
	g()->delta_time = g()->mlx->delta_time * 30;
	if (frame >= 1)
	{
		draw();
		if (g()->state == GAME)
		{
			move();
			player_animation_dir();
			mlx_get_mouse_pos(g()->mlx, &g()->mouse.x, &g()->mouse.y);
			if (is_key_pressed(MLX_KEY_P))
			{
				g()->mouse_id += 1;
				if (g()->mouse_id > 9)
					g()->mouse_id = 0;
				printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
			}
			if (is_key_pressed(MLX_KEY_O))
			{
				g()->mouse_id -= 1;
				if (g()->mouse_id < 0)
					g()->mouse_id = 9;
				printf("%d - %s\n", g()->mouse_id, g()->tile_type[g()->mouse_id].name);
			}
			if (is_key_pressed(MLX_KEY_M))
				print_2d_map_array(g()->map, R_WIDTH, R_HEIGHT);
			if (mlx_is_key_down(g()->mlx, MLX_KEY_ESCAPE))
			{
				del_img(&g()->old_img);
				del_img(&g()->img);
				g()->state = START;
			}
		}
		frame = 0;
	}
	frame += g()->delta_time;
	//uptade time
	g()->current_time += g()->mlx->delta_time;
	// update player grid pos
	g()->playerGrid.x = g()->player.x / SPRITE_SIZE;
	g()->playerGrid.y = g()->player.y / SPRITE_SIZE;
	// update offset
	g()->offSet.x = (g()->player.x % SPRITE_SIZE) - SPRITE_SIZE/2;
	g()->offSet.y = (g()->player.y % SPRITE_SIZE) - SPRITE_SIZE/2;
	// update cameraGrid pos
	g()->cameraGrid.x = g()->playerGrid.x - g()->window.c_width / 2;
	g()->cameraGrid.y = g()->playerGrid.y - g()->window.c_height / 2;
	g()->mouseGrid.x = g()->cameraGrid.x + ((g()->mouse.x + g()->offSet.x)
			/ SPRITE_SIZE);
	g()->mouseGrid.y = g()->cameraGrid.y + ((g()->mouse.y + g()->offSet.y)
			/ SPRITE_SIZE);
}

void	init_window(void)
{
	g()->window.width = 1344;
	g()->window.height = 704;
	g()->window.c_width = 21;
	g()->window.c_height = 11;
	g()->window.r_width = 10;
	g()->window.r_height = 10;
}

int32_t	main(void)
{
	g()->playerGrid.x = 5;
	g()->playerGrid.y = 5;
	g()->player.x = g()->playerGrid.x * SPRITE_SIZE;
	g()->player.y = g()->playerGrid.y * SPRITE_SIZE;
	g()->p_hitbox.top = 16;
	g()->p_hitbox.left = 12;
	g()->p_hitbox.right = 12;
	g()->arm_range = 20;
	g()->state = GAME;

	init_window();
	init_player_animation();

	//set tile type
	set_grass();
	set_hill();
	set_dirt();
	set_water();
	set_sand();
	set_deep_dirt();
	set_wood_floor();
	set_wood_wall();
	set_stone_floor();
	set_stone_wall();

	//GRID
	g()->map = allocate_2d_map_array(g()->window.r_width, g()->window.r_height);
	set_map(0, 0, g()->window.r_width, g()->window.r_height);
	auto_tiling(0, 0, g()->window.r_width, g()->window.r_height);

	//MLX
	g()->mlx = mlx_init(g()->window.width, g()->window.height, "MLX42", true);

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

	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}