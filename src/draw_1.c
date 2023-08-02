/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:22:40 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 14:29:14 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_menu(void)
{
	if (menu()->button[0]->count <= 0)
		mlx_image_to_window(g()->mlx, menu()->button[0], -32, 0);
	if (menu()->button[2]->count <= 0 && g()->state == PAUSE)
		mlx_image_to_window(g()->mlx, menu()->button[2], 448, 320);
	if (menu()->button[1]->count <= 0 && g()->state == START)
		mlx_image_to_window(g()->mlx, menu()->button[1], 448, 320);
	if (menu()->button[3]->count <= 0)
		mlx_image_to_window(g()->mlx, menu()->button[3], 448, 512);
	if (menu()->button[4]->count <= 0)
	{
		mlx_image_to_window(g()->mlx, menu()->button[4], 448, 320);
		mlx_image_to_window(g()->mlx, menu()->button[4], 448, 512);
	}
	if (menu()->button_slected == 0 && menu()->button[4]->count > 0)
	{
		menu()->button[4]->instances[0].enabled = true;
		menu()->button[4]->instances[1].enabled = false;
	}
	else if (menu()->button_slected == 1 && menu()->button[4]->count > 0)
	{
		menu()->button[4]->instances[0].enabled = false;
		menu()->button[4]->instances[1].enabled = true;
	}
}

void	draw_lami(void)
{
	t_vec2	pos;

	pos.x = lami()->pos.x - g()->cameraGrid.x * 64;
	pos.y = lami()->pos.y - g()->cameraGrid.y * 64;
	mlx_image_to_window(g()->mlx, g()->img.lami[lami()->animation.index], pos.x
		- g()->offSet.x, pos.y - g()->offSet.y);
}

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
