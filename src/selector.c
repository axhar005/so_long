/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:41:38 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 16:34:51 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	selector(void)
{
	if (point_distance(g()->playerGrid, g()->mouseGrid) <= g()->arm_range)
	{
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_RIGHT) && g()->dev_mod == true)
			if (replace_tile(g()->mouseGrid, g()->mouse_id))
				auto_tiling((t_vec2){g()->mouseGrid.x - 1, g()->mouseGrid.y
						- 1}, 3, 3);
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT)
			&& g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->id == TREE)
		{
			g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->life -= 5;
			if (g()->map[g()->mouseGrid.x][g()->mouseGrid.y]->life <= 0)
			{
				g()->cut_tree++;
				place_tile(g()->mouseGrid, DIRT);
				auto_tiling((t_vec2){g()->mouseGrid.x - 1, g()->mouseGrid.y
						- 1}, 3, 3);
			}
		}
		mlx_image_to_window(g()->mlx, g()->img.selector[0], (g()->mouseGrid.x
					- g()->cameraGrid.x) * 64 - g()->offSet.x, (g()->mouseGrid.y
					- g()->cameraGrid.y) * 64 - g()->offSet.y);
	}
}