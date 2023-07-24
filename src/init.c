/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:23:26 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/24 16:43:08 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_window(void)
{
	g()->window.width = 1216;
	g()->window.height = 704;
	g()->window.c_width = g()->window.width / SPRITE_SIZE;
	g()->window.c_height = g()->window.height / SPRITE_SIZE;
	g()->window.r_width = pars()->width;
	g()->window.r_height = pars()->height;
}

void	init_menu_start(void)
{
	g()->m_start.button[1] = mlx_texture_to_image(g()->mlx,
													g()->tex.wood_floor[0]);
	g()->m_start.button[0] = mlx_texture_to_image(g()->mlx,
													g()->tex.stone_floor[0]);
	g()->m_start.button_slected = 0;
}
