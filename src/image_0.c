/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:31 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/31 12:51:01 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(t_img *m, int i)
{
	while (i < 20)
	{
		if (i < 4)
		{
			m->crack[i] = mlx_texture_to_image(g()->mlx, g()->tex.crack[i]);
			m->portal[i] = mlx_texture_to_image(g()->mlx, g()->tex.portal[i]);
		}
		if (i < 10)
			m->player[i] = mlx_texture_to_image(g()->mlx, g()->tex.player[i]);
		if (i < 12)
			m->lami[i] = mlx_texture_to_image(g()->mlx, g()->tex.lami[i]);
		if (i < 16)
		{
			m->grass[i] = mlx_texture_to_image(g()->mlx, g()->tex.grass[i]);
			m->deep_dirt[i] = mlx_texture_to_image(g()->mlx,
													g()->tex.deep_dirt[i]);
			m->sand[i] = mlx_texture_to_image(g()->mlx, g()->tex.sand[i]);
			m->water[i] = mlx_texture_to_image(g()->mlx, g()->tex.water[i]);
		}
		if (i < 20)
		{
			m->hill[i] = mlx_texture_to_image(g()->mlx, g()->tex.hill[i]);
			m->wood_wall[i] = mlx_texture_to_image(g()->mlx,
													g()->tex.wood_wall[i]);
			m->stone_wall[i] = mlx_texture_to_image(g()->mlx,
													g()->tex.stone_wall[i]);
		}
		i++;
	}
}

void	init_img(t_img *img)
{
	int	i;

	i = 0;
	norm1(img, i);
	img->wood_floor[0] = mlx_texture_to_image(g()->mlx,
												g()->tex.wood_floor[0]);
	img->stone_floor[0] = mlx_texture_to_image(g()->mlx,
												g()->tex.stone_floor[0]);
	img->selector[0] = mlx_texture_to_image(g()->mlx, g()->tex.selector[0]);
	img->dirt[0] = mlx_texture_to_image(g()->mlx, g()->tex.dirt[0]);
	img->tree[0] = mlx_texture_to_image(g()->mlx, g()->tex.tree[0]);
}

static void	norm2(t_img *img, int i)
{
	while (i < 20)
	{
		if (i < 4)
		{
			mlx_delete_image(g()->mlx, img->crack[i]);
			mlx_delete_image(g()->mlx, img->portal[i]);
		}
		if (i < 10)
			mlx_delete_image(g()->mlx, img->player[i]);
		if (i < 12)
			mlx_delete_image(g()->mlx, img->lami[i]);
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
}

void	del_img(t_img *img)
{
	int	i;

	i = 0;
	norm2(img, i);
	mlx_delete_image(g()->mlx, img->wood_floor[0]);
	mlx_delete_image(g()->mlx, img->stone_floor[0]);
	mlx_delete_image(g()->mlx, img->selector[0]);
	mlx_delete_image(g()->mlx, img->dirt[0]);
	mlx_delete_image(g()->mlx, img->tree[0]);
}
