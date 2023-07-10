/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:35 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/10 14:09:42 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	map_image_to_window(mlx_image_t **img, t_pos2 co, bool under)
{
	if (under)
	{
		mlx_image_to_window(g()->mlx,
				img[g()->map[co.pos1.x][co.pos1.y]->under.tile_index], (co.pos2.x
					* SPRITE_SIZE) - g()->offSet.x, (co.pos2.y * SPRITE_SIZE)
				- g()->offSet.y);
	}
	else
	{
		mlx_image_to_window(g()->mlx,
				img[g()->map[co.pos1.x][co.pos1.y]->tile_index], (co.pos2.x
					* SPRITE_SIZE) - g()->offSet.x, (co.pos2.y * SPRITE_SIZE)
				- g()->offSet.y);
	}
}

void	map_image_index_to_window(mlx_image_t *img, t_pos2 co)
{
	mlx_image_to_window(g()->mlx, img, (co.pos2.x * SPRITE_SIZE)
			- g()->offSet.x, (co.pos2.y * SPRITE_SIZE) - g()->offSet.y);
}