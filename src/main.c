#include "../inc/so_long.h"

void	draw(void)
{
	if (g()->state == START)
	{
		if (g()->m_start.button[0]->count <= 0)
			mlx_image_to_window(g()->mlx, g()->m_start.button[0],
					(g()->window.c_width * SPRITE_SIZE) / 2-32,
					(g()->window.c_height * SPRITE_SIZE) / 2);
		if (g()->m_start.button[1]->count <= 0)
			mlx_image_to_window(g()->mlx, g()->m_start.button[1],
					(g()->window.c_width * SPRITE_SIZE) / 2-32,
					(g()->window.c_height * SPRITE_SIZE) / 2 + 128);
	}
	if (g()->state == GAME)
	{
		draw_grid(g()->cameraGrid.x, g()->cameraGrid.y, g()->map);
		selector();	
		mlx_image_to_window(g()->mlx, g()->img.player[g()->p_animation.index],
				((g()->window.c_width * SPRITE_SIZE) / 2) - SPRITE_SIZE / 2,
				((g()->window.c_height * SPRITE_SIZE) / 2) - SPRITE_SIZE / 2);
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
		if (g()->state == START)
		{
			
			if (is_key_pressed(MLX_KEY_W))
			{
				g()->m_start.button_slected += 1;
				if (g()->m_start.button_slected > 1)
					g()->m_start.button_slected = 0;
				printf("Button : %d\n", g()->m_start.button_slected);
			}
			else if (is_key_pressed(MLX_KEY_S))
			{
				g()->m_start.button_slected -= 1;
				if (g()->m_start.button_slected < 0)
					g()->m_start.button_slected = 1;
				printf("Button : %d\n", g()->m_start.button_slected);
			}
			if ((g()->m_start.button_slected == 1 && is_key_pressed(MLX_KEY_ENTER)) || is_key_pressed(MLX_KEY_ESCAPE))
			{
				clean_all();
				mlx_close_window(g()->mlx);
			}
			if (g()->m_start.button_slected == 0 && is_key_pressed(MLX_KEY_ENTER))
			{
				mlx_delete_image(g()->mlx, g()->m_start.button[0]);
				mlx_delete_image(g()->mlx, g()->m_start.button[1]);
				g()->state = GAME;
			}
		}
		else if (g()->state == GAME)
		{
			move();
			player_animation_dir();
			if (is_key_pressed(MLX_KEY_P))
			{
				g()->mouse_id += 1;
				if (g()->mouse_id > 11)
					g()->mouse_id = 1;
				printf("%d - %s\n", g()->mouse_id,
						g()->tile_type[g()->mouse_id].name);
			}
			if (is_key_pressed(MLX_KEY_O))
			{
				g()->mouse_id -= 1;
				if (g()->mouse_id < 1)
					g()->mouse_id = 11;
				printf("%d - %s\n", g()->mouse_id,
						g()->tile_type[g()->mouse_id].name);
			}
			if (is_key_pressed(MLX_KEY_M))
				print_2d_map_array(g()->map, g()->window.r_width,
						g()->window.r_height);
			if (is_key_pressed(MLX_KEY_ESCAPE))
			{
				del_img(&g()->old_img);
				del_img(&g()->img);
				init_menu_start();
				g()->state = START;
			}
		}
		frame = 0;
		draw();
		mlx_get_mouse_pos(g()->mlx, &g()->mouse.x, &g()->mouse.y);
	}
	frame += g()->delta_time;
	//uptade time
	g()->current_time += mlx_get_time();
	// update player grid pos
	g()->playerGrid.x = g()->player.x / SPRITE_SIZE;
	g()->playerGrid.y = g()->player.y / SPRITE_SIZE;
	// update offset
	g()->offSet.x = (g()->player.x % SPRITE_SIZE) - SPRITE_SIZE / 2;
	g()->offSet.y = (g()->player.y % SPRITE_SIZE) - SPRITE_SIZE / 2;
	// update cameraGrid pos
	g()->cameraGrid.x = g()->playerGrid.x - g()->window.c_width / 2;
	g()->cameraGrid.y = g()->playerGrid.y - g()->window.c_height / 2;
	//update mouse possition
	g()->mouseGrid.x = g()->cameraGrid.x + ((g()->mouse.x + g()->offSet.x)
			/ SPRITE_SIZE);
	g()->mouseGrid.y = g()->cameraGrid.y + ((g()->mouse.y + g()->offSet.y)
			/ SPRITE_SIZE);
}

int32_t	main(int ac, char **av)
{
	if (ac == 2)
    {
        path_parsing(av[1], ".ber");
        pars()->map = load_map(av[1]);
        if (!pars()->map)
            ft_exit("Error\n> when loading map");
        map_parsing();
	}
	else
        ft_exit("Error> one argument needed (map.ber)");

	g()->playerGrid = char_find_pos_2d(pars()->map, 'P');
	g()->player.x = g()->playerGrid.x * SPRITE_SIZE+32;
	g()->player.y = g()->playerGrid.y * SPRITE_SIZE+32;
	g()->p_hitbox.top = 16;
	g()->p_hitbox.left = 12;
	g()->p_hitbox.right = 12;
	g()->arm_range = 100;
	g()->state = GAME;
	g()->mouse_id = 1;

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
	set_tree();

	//GRID
	g()->map = allocate_2d_map_array(g()->window.r_width, g()->window.r_height);
	load_in_map();
	set_map(0, 0, g()->window.r_width, g()->window.r_height);
	auto_tiling((t_vec2){0,0}, g()->window.r_width, g()->window.r_height);

	//MLX
	g()->mlx = mlx_init(g()->window.width, g()->window.height, "MLX42", false);

	//load texture
	init_all_texture();

	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}
