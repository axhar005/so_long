/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:21:54 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/10 14:05:14 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_tree(void)
{
	g()->tile_type[TREE].name = "tree";
	g()->tile_type[TREE].id = TREE;
	g()->tile_type[TREE].image = g()->img.tree;
	g()->tile_type[TREE].depth = WALL;
	g()->tile_type[TREE].life = 100;
	g()->tile_type[TREE].solid = true;
	g()->tile_type[TREE].tile_index = 0;
    tile_to_under(&g()->tile_type[GRASS], &g()->tile_type[TREE].under);
}
