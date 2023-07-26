#include "../inc/so_long.h"

void	draw_lami(void)
{
	t_vec2	pos;

	pos.x = lami()->pos.x - g()->cameraGrid.x * 64;
	pos.y = lami()->pos.y - g()->cameraGrid.y * 64;
	mlx_image_to_window(g()->mlx, g()->img.player[g()->p_animation.index], pos.x
			- g()->offSet.x, pos.y - g()->offSet.y);
}

void	step_lami(void)
{
	int32_t r1;
	int32_t r2;

	if (g()->current_time >= lami()->time + 5000)
	{
		r1 = rand() % 2;
		if (r1 == 0)
			r1 = -1;
		r2 = rand() % 2;
		if (r2 == 0)
			r2 = -1;

		lami()->move.hspd = r1;
		lami()->move.vspd = r2;
		lami()->time = g()->current_time;
	}
	// lami()->move.hspd = (mlx_is_key_down(g()->mlx, MLX_KEY_RIGHT)
	// 		- mlx_is_key_down(g()->mlx, MLX_KEY_LEFT)) * lami()->move.spd;
	// lami()->move.vspd = (mlx_is_key_down(g()->mlx, MLX_KEY_DOWN)
	// 		- mlx_is_key_down(g()->mlx, MLX_KEY_UP)) * lami()->move.spd;

	movement(&lami()->pos, &lami()->move.hspd, g()->p_hitbox, false);
	movement(&lami()->pos, &lami()->move.vspd, g()->p_hitbox, true);
}

void	draw(void)
{
	if (g()->state == PAUSE || g()->state == START)
	{
		draw_menu();
	}
	else if (g()->state == GAME)
	{
		draw_grid(g()->cameraGrid.x, g()->cameraGrid.y, g()->map);
		selector();
		draw_lami();
		mlx_image_to_window(g()->mlx, g()->img.player[g()->p_animation.index],
				((g()->window.c_width * SPRITE_SIZE) / 2) - SPRITE_SIZE / 2,
				((g()->window.c_height * SPRITE_SIZE) / 2) - SPRITE_SIZE / 2);
	}
}

void	step(void *param)
{
	static double	frame;

	(void)param;
	g()->delta_time = g()->mlx->delta_time * 30;
	if (frame >= 1)
	{
		if (g()->state == PAUSE || g()->state == START)
		{
			step_menu();
		}
		else if (g()->state == GAME)
		{
			step_game();
			step_lami();
		}
		frame = 0;
		draw();
		mlx_get_mouse_pos(g()->mlx, &g()->mouse.x, &g()->mouse.y);
	}
	frame += g()->delta_time;
	step_update();
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
	init_all();
	//MLX
	g()->mlx = mlx_init(g()->window.width, g()->window.height, "MLX42", true);
	init_all_texture();
	init_menu();
	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}
