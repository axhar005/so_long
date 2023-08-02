/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:00:26 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/02 14:12:45 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	norm1(int i)
{
	if (i < 4)
	{
		mlx_delete_texture(g()->tex.crack[i]);
		mlx_delete_texture(g()->tex.portal[i]);
	}
	if (i < 5)
		mlx_delete_texture(menu()->tex[i]);
	if (i < 10)
		mlx_delete_texture(g()->tex.player[i]);
	if (i < 12)
		mlx_delete_texture(g()->tex.lami[i]);
	if (i < 16)
	{
		mlx_delete_texture(g()->tex.grass[i]);
		mlx_delete_texture(g()->tex.sand[i]);
		mlx_delete_texture(g()->tex.water[i]);
		mlx_delete_texture(g()->tex.deep_dirt[i]);
	}
	mlx_delete_texture(g()->tex.hill[i]);
	mlx_delete_texture(g()->tex.stone_wall[i]);
	mlx_delete_texture(g()->tex.wood_wall[i]);
	i++;
}

void	del_texture(void)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		norm1(i);
	}
	mlx_delete_texture(g()->tex.dirt[0]);
	mlx_delete_texture(g()->tex.wood_floor[0]);
	mlx_delete_texture(g()->tex.stone_floor[0]);
	mlx_delete_texture(g()->tex.selector[0]);
}

static void	is_null_exit(void *ptr, char *msg)
{
	if (!ptr)
		ft_exit(msg);
}

static void	norm2(int i, char *msg)
{
	if (i < 4)
	{
		is_null_exit(g()->tex.crack[i], msg);
		is_null_exit(g()->tex.portal[i], msg);
	}
	if (i < 5)
		is_null_exit(menu()->tex[i], msg);
	if (i < 12)
		is_null_exit(g()->tex.lami[i], msg);
	if (i < 16)
	{
		is_null_exit(g()->tex.grass[i], msg);
		is_null_exit(g()->tex.sand[i], msg);
		is_null_exit(g()->tex.water[i], msg);
		is_null_exit(g()->tex.deep_dirt[i], msg);
	}
}

void	is_null_texture(void)
{
	int		i;
	char	*msg;

	i = 0;
	msg = "Error\n> texture not loaded !";
	while (i < 20)
	{
		norm2(i, msg);
		is_null_exit(g()->tex.hill[i], msg);
		is_null_exit(g()->tex.stone_wall[i], msg);
		is_null_exit(g()->tex.wood_wall[i], msg);
		i++;
	}
	is_null_exit(g()->tex.dirt[0], msg);
	is_null_exit(g()->tex.wood_floor[0], msg);
	is_null_exit(g()->tex.stone_floor[0], msg);
	is_null_exit(g()->tex.selector[0], msg);
	is_null_exit(g()->tex.tree[0], msg);
}
