/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_convertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:26:05 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/10 13:50:01 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	tile_to_under(t_tile *tile, t_tile_under *under)
{
	under->depth = tile->depth;
	under->id = tile->id;
	under->image = tile->image;
	under->life = tile->life;
	under->name = tile->name;
	under->solid = tile->solid;
	under->tile_index = tile->tile_index;
}

void	under_to_tile(t_tile_under *under, t_tile *tile)
{
	tile->depth = under->depth;
	tile->id = under->id;
	tile->image = under->image;
	tile->life = under->life;
	tile->name = under->name;
	tile->solid = under->solid;
	tile->tile_index = under->tile_index;
}