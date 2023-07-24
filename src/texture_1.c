/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:00:26 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/24 12:37:41 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	del_texture(void)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
			mlx_delete_texture(g()->tex.crack[i]);
		if (i < 16)
		{
			mlx_delete_texture(g()->tex.grass[i]);
			mlx_delete_texture(g()->tex.sand[i]);
			mlx_delete_texture(g()->tex.water[i]);
			mlx_delete_texture(g()->tex.deep_dirt[i]);
		}
		mlx_delete_texture(g()->tex.hill[i]);
		mlx_delete_texture(g()->tex.stone_wall[i]);
		mlx_delete_texture(g()->tex.wood_wall[i]);
		i++;
	}
	mlx_delete_texture(g()->tex.dirt[0]);
	mlx_delete_texture(g()->tex.wood_floor[0]);
	mlx_delete_texture(g()->tex.stone_floor[0]);
	mlx_delete_texture(g()->tex.selector[0]);
	mlx_delete_texture(g()->tex.tree[0]);
}
