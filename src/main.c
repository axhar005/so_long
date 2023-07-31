#include "../inc/so_long.h"

void	draw_feet_count(void)
{
	static mlx_image_t	*old_temp;
	static mlx_image_t	*temp;
	char				*msg;

	msg = ft_stringf("%d", g()->feet_step);
	mlx_delete_image(g()->mlx, old_temp);
	old_temp = temp;
	temp = mlx_put_string(g()->mlx, msg, ((g()->window.c_width * SPRITE_SIZE)
				/ 2) - (5 * ft_strlen(msg)), ((g()->window.c_height
					* SPRITE_SIZE) / 2) - SPRITE_SIZE);
	ft_sfree(msg);
}

int	rand_range(int min, int max)
{
	int	temp;
	int	r_size;
	int	r_number;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	r_size = max - min + 1;
	r_number = (rand() % r_size) + min;
	return (r_number);
}

void	draw_lami(void)
{
	t_vec2	pos;

	pos.x = lami()->pos.x - g()->cameraGrid.x * 64;
	pos.y = lami()->pos.y - g()->cameraGrid.y * 64;
	mlx_image_to_window(g()->mlx, g()->img.lami[lami()->animation.index], pos.x
			- g()->offSet.x, pos.y - g()->offSet.y);
}

void	death(void)
{
	if (g()->player.x - g()->p_hitbox.left > lami()->pos.x - lami()->hitbox.left
		&& g()->player.x + g()->p_hitbox.right < (lami()->pos.x
			+ lami()->hitbox.right) + SPRITE_SIZE)
	{
		if (g()->player.y - -g()->p_hitbox.top
			- lami()->hitbox.top > lami()->pos.y
			&& g()->player.y < (lami()->pos.y + lami()->hitbox.bot)
			+ SPRITE_SIZE)
			ft_exit("You died !");
	}
}

void	step_lami(void)
{
	static int32_t	last_h;

	if (g()->current_time >= lami()->time + rand_range(5000, 100000))
	{
		lami()->move.hspd = rand() % 2;
		if (lami()->move.hspd == 0)
			lami()->move.hspd = -1;
		lami()->move.vspd = rand() % 2;
		if (lami()->move.vspd == 0)
			lami()->move.vspd = -1;
		lami()->time = g()->current_time;
	}
	if (lami()->move.hspd != 0)
		last_h = lami()->move.hspd;
	if (lami()->move.hspd == 0 && lami()->move.vspd == 0)
		last_h = 0;
	movement(&lami()->pos, &lami()->move.hspd, lami()->hitbox, false);
	movement(&lami()->pos, &lami()->move.vspd, lami()->hitbox, true);
	if (lami()->move.hspd == 1 || (lami()->move.hspd == 0 && last_h == 1))
		play_animation(&lami()->animation, lami()->animation.right);
	else if (lami()->move.hspd == -1 || (lami()->move.hspd == 0 
		&& last_h == -1))
		play_animation(&lami()->animation, lami()->animation.left);
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
		draw_feet_count();
	}
}

void	step_portal(void)
{
	static double	laste_time;
	static t_vec2	exit_pos;
	t_vec2			origin;

	origin.x = g()->player.x - SPRITE_SIZE / 2;
	origin.y = g()->player.y - SPRITE_SIZE / 2;
	if (exit_pos.x == 0 && exit_pos.y == 0)
		exit_pos = char_find_pos_2d(pars()->map, 'E');
	if (g()->cut_tree == pars()->char_c)
	{
		if (g()->current_time >= laste_time + 100)
		{
			if (g()->map[exit_pos.x][exit_pos.y]->tile_index < 3)
				g()->map[exit_pos.x][exit_pos.y]->tile_index += 1;
			else
				g()->map[exit_pos.x][exit_pos.y]->tile_index = 1;
			laste_time = g()->current_time;
		}
		if (tile_collision(origin.x + g()->p_hitbox.left, (origin.y
					+ g()->p_hitbox.top), SPRITE_SIZE - (g()->p_hitbox.right
					+ g()->p_hitbox.left), SPRITE_SIZE - (g()->p_hitbox.bot
					+ g()->p_hitbox.top), PORTAL))
			ft_exit("Good Job");
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
			step_portal();
			death();
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
