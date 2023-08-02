/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:06:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 14:05:23 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_player_texture(void)
{
	t_game	*ga;

	ga = g();
	ga->tex.player[0] = mlx_load_png("./asset/player/player_down_0.png");
	ga->tex.player[1] = mlx_load_png("./asset/player/player_down_1.png");
	ga->tex.player[2] = mlx_load_png("./asset/player/player_up_0.png");
	ga->tex.player[3] = mlx_load_png("./asset/player/player_up_1.png");
	ga->tex.player[4] = mlx_load_png("./asset/player/player_left_0.png");
	ga->tex.player[5] = mlx_load_png("./asset/player/player_left_1.png");
	ga->tex.player[6] = mlx_load_png("./asset/player/player_left_2.png");
	ga->tex.player[7] = mlx_load_png("./asset/player/player_right_0.png");
	ga->tex.player[8] = mlx_load_png("./asset/player/player_right_1.png");
	ga->tex.player[9] = mlx_load_png("./asset/player/player_right_2.png");
}

static void	init_menu_texture(void)
{
	menu()->tex[0] = mlx_load_png("./asset/menu/start_menu_empty.png");
	menu()->tex[1] = mlx_load_png("./asset/menu/b_play.png"); 
	menu()->tex[2] = mlx_load_png("./asset/menu/b_continue.png");
	menu()->tex[3] = mlx_load_png("./asset/menu/b_quit.png");
	menu()->tex[4] = mlx_load_png("./asset/menu/select_button.png");
}

static mlx_texture_t	*mlx_free(char *path)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(path);
	ft_sfree(path);
	return (temp);
}

static void	norm1(int i)
{
	t_game	*ga;

	ga = g();
	if (i < 4)
	{
		ga->tex.crack[i] = \
			mlx_free(ft_stringf("./asset/crack/crack_%d.png", i));
		ga->tex.portal[i] = \
			mlx_free(ft_stringf("./asset/portal/portal_%d.png", i));
	}
	if (i < 12)
		ga->tex.lami[i] = \
			mlx_free(ft_stringf("./asset/lami/lami_%d.png", i));
	if (i < 16)
	{
		ga->tex.grass[i] = \
			mlx_free(ft_stringf("./asset/grass/grass_%d.png", i));
		ga->tex.sand[i] = \
			mlx_free(ft_stringf("./asset/sand/sand_%d.png", i));
		ga->tex.water[i] = \
			mlx_free(ft_stringf("./asset/water/water_%d.png", i));
		ga->tex.deep_dirt[i] = \
			mlx_free(ft_stringf("./asset/deep_dirt/deep_dirt_%d.png", i));
	}
}

void	init_all_texture(void)
{
	t_game	*ga;
	int		i;

	ga = g();
	i = 0;
	while (i < 20)
	{
		norm1(i);
		ga->tex.hill[i] = \
			mlx_free(ft_stringf("./asset/hill/hill_%d.png", i));
		ga->tex.stone_wall[i] = \
			mlx_free(ft_stringf("./asset/stone/wall/stone_wall_%d.png", i));
		ga->tex.wood_wall[i] = \
			mlx_free(ft_stringf("./asset/wood/wall/wood_wall_%d.png", i));
		i++;
	}
	ga->tex.wood_floor[0] = mlx_load_png("./asset/wood/floor/wood_floor.png");
	ga->tex.stone_floor[0] = \
		mlx_load_png("./asset/stone/floor/stone_floor.png");
	ga->tex.selector[0] = mlx_load_png("./asset/selector.png");
	ga->tex.dirt[0] = mlx_load_png("./asset/dirt/dirt_0.png");
	ga->tex.tree[0] = mlx_load_png("./asset/tree/tree_0.png");
	init_player_texture();
	init_menu_texture();
	is_null_texture();
}
