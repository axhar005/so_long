/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 16:57:23 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
			img->crack[i] = mlx_texture_to_image(g()->mlx, g()->tex.crack[i]);
		if (i < 10)
			img->player[i] = mlx_texture_to_image(g()->mlx, g()->tex.player[i]);
		if (i < 16)
		{
			img->grass[i] = mlx_texture_to_image(g()->mlx, g()->tex.grass[i]);
			img->deep_dirt[i] = mlx_texture_to_image(g()->mlx,
					g()->tex.deep_dirt[i]);
			img->sand[i] = mlx_texture_to_image(g()->mlx, g()->tex.sand[i]);
			img->water[i] = mlx_texture_to_image(g()->mlx, g()->tex.water[i]);
		}
		if (i < 20)
		{
			img->hill[i] = mlx_texture_to_image(g()->mlx, g()->tex.hill[i]);
			img->wood_wall[i] = mlx_texture_to_image(g()->mlx, g()->tex.wood_wall[i]);
			img->stone_wall[i] = mlx_texture_to_image(g()->mlx, g()->tex.stone_wall[i]);
		}
		i++;
	}
	img->wood_floor[0] = mlx_texture_to_image(g()->mlx,
			g()->tex.wood_floor[0]);
	img->stone_floor[0] = mlx_texture_to_image(g()->mlx,
			g()->tex.stone_floor[0]);
	img->selector[0] = mlx_texture_to_image(g()->mlx, g()->tex.selector[0]);
	img->dirt[0] = mlx_texture_to_image(g()->mlx, g()->tex.dirt[0]);
}

void	del_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
			mlx_delete_image(g()->mlx, img->crack[i]);
		if (i < 10)
			mlx_delete_image(g()->mlx, img->player[i]);
		if (i < 16)
		{
			mlx_delete_image(g()->mlx, img->grass[i]);
			mlx_delete_image(g()->mlx, img->deep_dirt[i]);
			mlx_delete_image(g()->mlx, img->sand[i]);
			mlx_delete_image(g()->mlx, img->water[i]);
		}
		if (i < 20)
		{
			mlx_delete_image(g()->mlx, img->hill[i]);
			mlx_delete_image(g()->mlx, img->wood_wall[i]);
			mlx_delete_image(g()->mlx, img->stone_wall[i]);
		}
		i++;
	}
	mlx_delete_image(g()->mlx, img->wood_floor[0]);
	mlx_delete_image(g()->mlx, img->stone_floor[0]);
	mlx_delete_image(g()->mlx, img->selector[0]);
	mlx_delete_image(g()->mlx, img->dirt[0]);
}
