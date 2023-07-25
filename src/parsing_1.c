/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:23:06 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/25 14:15:51 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	copy_2d_char(void)
{
	int	x;

	x = 0;
	pars()->mapf = ft_gnl_calloc(pars()->height + 1, sizeof(char *));
	while (pars()->map[x])
	{
		pars()->mapf[x] = ft_strdup(pars()->map[x]);
		x++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == 'p' || map[x][y] == 'c' || map[x][y] == 'e'
		|| map[x][y] == 'o' || map[x][y] == '1' || map[x][y] == 'd'
		|| map[x][y] == '3')
		return ;
	if (map[x][y] == '0')
		map[x][y] = 'o';
	else if (map[x][y] == '2')
		map[x][y] = 'd';
	else if (map[x][y] == 'E')
		map[x][y] = 'e';
	else if (map[x][y] == 'C')
		map[x][y] = 'c';
	else if (map[x][y] == 'P')
		map[x][y] = 'p';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	after_flood(void)
{
	if (char_count_2d(pars()->mapf, 'e') != pars()->char_e)
		ft_exit("Error\n> exit obstructed");
	if (char_count_2d(pars()->mapf, 'c') != pars()->char_c)
		ft_exit("Error\n> on or more collectible obstructed");
	if (char_count_2d(pars()->mapf, 'p') != 1)
		ft_exit("Error\n> player obstructed");
	if (char_count_2d(pars()->mapf, 'e') != 1)
		ft_exit("Error\n> exit obstructed");
}

void	map_parsing(void)
{
	init_parsing();
	map_is_rectangle(pars()->map);
	map_is_closed();
	map_parsing_element();
	copy_2d_char();
	flood_fill(pars()->mapf, 1, 1);
	after_flood();
}