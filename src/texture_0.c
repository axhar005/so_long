/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/31 12:55:50 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_player_texture(void)
{
	g()->tex.player[0] = mlx_load_png("./asset/player/player_down_0.png");
	g()->tex.player[1] = mlx_load_png("./asset/player/player_down_1.png");
	g()->tex.player[2] = mlx_load_png("./asset/player/player_up_0.png");
	g()->tex.player[3] = mlx_load_png("./asset/player/player_up_1.png");
	g()->tex.player[4] = mlx_load_png("./asset/player/player_left_0.png");
	g()->tex.player[5] = mlx_load_png("./asset/player/player_left_1.png");
	g()->tex.player[6] = mlx_load_png("./asset/player/player_left_2.png");
	g()->tex.player[7] = mlx_load_png("./asset/player/player_right_0.png");
	g()->tex.player[8] = mlx_load_png("./asset/player/player_right_1.png");
	g()->tex.player[9] = mlx_load_png("./asset/player/player_right_2.png");
}

static void	init_menu_texture(void)
{
	menu()->tex[0] = mlx_load_png("./asset/menu/start_menu_empty.png"); 
	menu()->tex[1] = mlx_load_png("./asset/menu/b_play.png"); 
	menu()->tex[2] = mlx_load_png("./asset/menu/b_continue.png");
	menu()->tex[3] = mlx_load_png("./asset/menu/b_quit.png");
	menu()->tex[4] = mlx_load_png("./asset/menu/select_button.png");
}

static mlx_texture_t	*mlx_png_free(char *path)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(path);
	ft_sfree(path);
	return (temp);
}

void	init_all_texture(void)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i < 4)
		{
			g()->tex.crack[i] = mlx_png_free(ft_stringf("./asset/crack/crack_%d.png", i));
			g()->tex.portal[i] = mlx_png_free(ft_stringf("./asset/portal/portal_%d.png", i));
		}
		if (i < 12)
			g()->tex.lami[i] = mlx_png_free(ft_stringf("./asset/lami/lami_%d.png", i));
		if (i < 16)
		{
			g()->tex.grass[i] = mlx_png_free(ft_stringf("./asset/grass/grass_%d.png",i));
			g()->tex.sand[i] = mlx_png_free(ft_stringf("./asset/sand/sand_%d.png",i));
			g()->tex.water[i] = mlx_png_free(ft_stringf("./asset/water/water_%d.png",i));
			g()->tex.deep_dirt[i] = mlx_png_free(ft_stringf("./asset/deep_dirt/deep_dirt_%d.png",i));
		}
		g()->tex.hill[i] = mlx_png_free(ft_stringf("./asset/hill/hill_%d.png",i));
		g()->tex.stone_wall[i] = mlx_png_free(ft_stringf("./asset/stone/stone_wall/stone_wall_%d.png",i));
		g()->tex.wood_wall[i] = mlx_png_free(ft_stringf("./asset/wood/wood_wall/wood_wall_%d.png",i));
		i++;
	}
	g()->tex.wood_floor[0] = mlx_load_png("./asset/wood/wood_floor/wood_floor.png");
	g()->tex.stone_floor[0] = mlx_load_png("./asset/stone/stone_floor/stone_floor.png");
	g()->tex.selector[0] = mlx_load_png("./asset/selector.png");
	g()->tex.dirt[0] = mlx_load_png("./asset/dirt/dirt_0.png");
	g()->tex.tree[0] = mlx_load_png("./asset/tree/tree_0.png");
	init_player_texture();
	init_menu_texture();
	is_null_texture();
}
