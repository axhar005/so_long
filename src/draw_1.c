/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:22:40 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 15:34:39 by oboucher         ###   ########.fr       */
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