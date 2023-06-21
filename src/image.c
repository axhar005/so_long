/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/20 21:32:59 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 10)
			img->player[i] = mlx_texture_to_image(game->mlx, game->tex.player[i]);
		if (i < 16)
		{
			img->grass[i] = mlx_texture_to_image(game->mlx, game->tex.grass[i]);
			img->dirt[i] = mlx_texture_to_image(game->mlx, game->tex.dirt[i]);
			img->sand[i] = mlx_texture_to_image(game->mlx, game->tex.sand[i]);
			img->water[i] = mlx_texture_to_image(game->mlx, game->tex.water[i]);
		}
		if (i < 20)
			img->wall[i] = mlx_texture_to_image(game->mlx, game->tex.wall[i]);
		i++;
	}
	img->plank_floor = mlx_texture_to_image(game->mlx, game->tex.plank_floor);
	img->stone_floor = mlx_texture_to_image(game->mlx, game->tex.stone_floor);
	img->selector = mlx_texture_to_image(game->mlx, game->tex.selector);
}

void	del_img(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 10)
			mlx_delete_image(game->mlx, img->player[i]);
		if (i < 16)
		{
			mlx_delete_image(game->mlx, img->grass[i]);
			mlx_delete_image(game->mlx, img->dirt[i]);
			mlx_delete_image(game->mlx, img->sand[i]);
			mlx_delete_image(game->mlx, img->water[i]);
		}
		if (i < 20)
			mlx_delete_image(game->mlx, img->wall[i]);
		i++;
	}
	mlx_delete_image(game->mlx, img->plank_floor);
	mlx_delete_image(game->mlx, img->stone_floor);
	mlx_delete_image(game->mlx, img->selector);
}
