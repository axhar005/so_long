/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:21:46 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 14:50:32 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	path_parsing(char *path, char *ext)
{
	if (ft_strncmp(&path[ft_strlen(path) - 4], ext, 4))
		ft_exit(ft_stringf("Error\n> incorrect path (%s needed)", ext));
	if (ft_strlen(path) < 5)
		ft_exit("Error\n> incorrect path (name.ber needed)");
}

void	map_is_rectangle(char **map)
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(map[0]);
	if (len <= 0 || line_count(map) < 3)
		ft_exit("Error\n> rectangular map needed (more then 2 line in map)");
	while (map[x])
	{
		if (ft_strlen(map[x]) != len)
			ft_exit("Error\n> rectangular map needed");
		x++;
	}
}

void	map_is_closed(void)
{
	size_t	x;

	if (char_count(pars()->map[0], '1') != ft_strlen(pars()->map[0])
		|| char_count(pars()->map[pars()->height - 1],
			'1') != ft_strlen(pars()->map[pars()->height - 1]))
		ft_exit("Error\n> closed by walls needed");
	x = 1;
	while (x < pars()->height - 1)
	{
		if (pars()->map[x][0] != '1' || pars()->map[x][ft_strlen(pars()->map[x])
			- 1] != '1')
			ft_exit("Error\n> closed by walls needed");
		x++;
	}
}

void	map_parsing_element(void)
{
	if (pars()->char_c < 1)
		ft_exit("Error\n> colectables 'C' needed");
	if (pars()->char_e < 1 || pars()->char_e > 1)
		ft_exit("Error\n> one exit 'E' needed");
	if (pars()->char_p < 1 || pars()->char_p > 1)
		ft_exit("Error\n> one player 'P' needed");
	if (pars()->char_0 + pars()->char_1 + pars()->char_e + pars()->char_p
		+ pars()->char_c != total_count(pars()->map))
		ft_exit("Error\n> we need and accept only this chars (0,1,2,3,E,P,C)");
}

void	init_parsing(void)
{
	pars()->height = line_count(pars()->map);
	pars()->width = ft_strlen(pars()->map[0]);
	pars()->char_0 = char_count_2d(pars()->map, '0')
		+ char_count_2d(pars()->map, '2');
	pars()->char_1 = char_count_2d(pars()->map, '1')
		+ char_count_2d(pars()->map, '3');
	pars()->char_e = char_count_2d(pars()->map, 'E');
	pars()->char_p = char_count_2d(pars()->map, 'P');
	pars()->char_c = char_count_2d(pars()->map, 'C');
}
