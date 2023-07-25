/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:24:24 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 15:44:27 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(void)
{
	if (is_key_pressed(MLX_KEY_W))
	{
		menu()->button_slected += 1;
		if (menu()->button_slected > 1)
			menu()->button_slected = 0;
	}
	else if (is_key_pressed(MLX_KEY_S))
	{
		menu()->button_slected -= 1;
		if (menu()->button_slected < 0)
			menu()->button_slected = 1;
	}
	if ((menu()->button_slected == 1 && (is_key_pressed(MLX_KEY_ENTER)
				|| is_key_pressed(MLX_KEY_SPACE)))
		|| is_key_pressed(MLX_KEY_ESCAPE))
	{
		clean_all();
		mlx_close_window(g()->mlx);
	}
	if (menu()->button_slected == 0 && (is_key_pressed(MLX_KEY_ENTER)
			|| is_key_pressed(MLX_KEY_SPACE)))
	{
		del_menu_img(menu());
		g()->state = GAME;
	}
}

void	step_menu(void)
{
	norm1();
	if (mouse_button(448, 320, SPRITE_SIZE * 5, SPRITE_SIZE))
	{
		menu()->button_slected = 0;
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT))
		{
			del_menu_img(menu());
			g()->state = GAME;
		}
	}
	else if (mouse_button(448, 512, SPRITE_SIZE * 5, SPRITE_SIZE))
	{
		menu()->button_slected = 1;
		if (mlx_is_mouse_down(g()->mlx, MLX_MOUSE_BUTTON_LEFT))
		{
			clean_all();
			mlx_close_window(g()->mlx);
		}
	}
}