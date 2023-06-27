/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/27 15:54:57 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
			img->crack[i] = mlx_texture_to_image(game->mlx, game->tex.crack[i]);
		if (i < 10)
			img->player[i] = mlx_texture_to_image(game->mlx, game->tex.player[i]);
		if (i < 16)
		{
			img->grass[i] = mlx_texture_to_image(game->mlx, game->tex.grass[i]);
			img->deep_dirt[i] = mlx_texture_to_image(game->mlx, game->tex.deep_dirt[i]);
			img->sand[i] = mlx_texture_to_image(game->mlx, game->tex.sand[i]);
			img->water[i] = mlx_texture_to_image(game->mlx, game->tex.water[i]);
		}
		if (i < 20)
			img->wall[i] = mlx_texture_to_image(game->mlx, game->tex.wall[i]);
		i++;
	}
	img->plank_floor[0] = mlx_texture_to_image(game->mlx, game->tex.plank_floor[0]);
	img->stone_floor[0] = mlx_texture_to_image(game->mlx, game->tex.stone_floor[0]);
	img->selector[0] = mlx_texture_to_image(game->mlx, game->tex.selector[0]);
	img->dirt[0] = mlx_texture_to_image(game->mlx, game->tex.dirt[0]);
}

void	del_img(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
			mlx_delete_image(game->mlx, img->crack[i]);
		if (i < 10)
			mlx_delete_image(game->mlx, img->player[i]);
		if (i < 16)
		{
			mlx_delete_image(game->mlx, img->grass[i]);
			mlx_delete_image(game->mlx, img->deep_dirt[i]);
			mlx_delete_image(game->mlx, img->sand[i]);
			mlx_delete_image(game->mlx, img->water[i]);
		}
		if (i < 20)
			mlx_delete_image(game->mlx, img->wall[i]);
		i++;
	}
	mlx_delete_image(game->mlx, img->plank_floor[0]);
	mlx_delete_image(game->mlx, img->stone_floor[0]);
	mlx_delete_image(game->mlx, img->selector[0]);
	mlx_delete_image(game->mlx, img->dirt[0]);
}
