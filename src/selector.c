/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:41:38 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/03 11:17:33 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(void)
{
	mlx_image_to_window(g()->mlx, g()->img.selector[0], (g()->mousegrid.x
			- g()->cameragrid.x) * 64 - g()->offset.x, (g()->mousegrid.y
			- g()->cameragrid.y) * 64 - g()->offset.y);
}

void	selector(void)
{
	if (point_distance(g()->playergrid, g()->mousegrid) <= g()->arm_range)
	{
		if ((g()->mousegrid.x >= 0 \
			&& g()->mousegrid.x <= g()->window.r_width * SPRITE_SIZE))
		{
			if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_RIGHT)
				&& g()->dev_mod == true)
				if (replace_tile(g()->mousegrid, g()->mouse_id))
					auto_tiling((t_vec2){g()->mousegrid.x - 1, g()->mousegrid.y
						- 1}, 3, 3);
			if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT)
				&& g()->map[g()->mousegrid.x][g()->mousegrid.y]->id == TREE)
			{
				g()->map[g()->mousegrid.x][g()->mousegrid.y]->life -= SPEED;
				if (g()->map[g()->mousegrid.x][g()->mousegrid.y]->life <= 0)
				{
					g()->cut_tree++;
					place_tile(g()->mousegrid, DIRT);
					auto_tiling((t_vec2){g()->mousegrid.x - 1, g()->mousegrid.y
						- 1}, 3, 3);
				}
			}
		}
		norm1();
	}
}
