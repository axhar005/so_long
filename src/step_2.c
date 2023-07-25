/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:28:41 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:35 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	step_update(void)
{
	//uptade time
	g()->current_time += mlx_get_time();
	// update player grid pos
	g()->playerGrid.x = g()->player.x / SPRITE_SIZE;
	g()->playerGrid.y = g()->player.y / SPRITE_SIZE;
	// update offset
	g()->offSet.x = (g()->player.x % SPRITE_SIZE) - SPRITE_SIZE / 2;
	g()->offSet.y = (g()->player.y % SPRITE_SIZE) - SPRITE_SIZE / 2;
	// update cameraGrid pos
	g()->cameraGrid.x = g()->playerGrid.x - g()->window.c_width / 2;
	g()->cameraGrid.y = g()->playerGrid.y - g()->window.c_height / 2;
	//update mouse possition
	g()->mouseGrid.x = g()->cameraGrid.x + ((g()->mouse.x + g()->offSet.x)
			/ SPRITE_SIZE);
	g()->mouseGrid.y = g()->cameraGrid.y + ((g()->mouse.y + g()->offSet.y)
			/ SPRITE_SIZE);
}