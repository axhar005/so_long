/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:51 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 15:11:57 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	t_game	*ga;

	ga = g();
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
	ga->mlx = mlx_init(g()->window.width, g()->window.height, "MLX42", false);
	init_all_texture();
	init_menu();
	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}
