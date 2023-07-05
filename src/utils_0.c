/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:37 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/05 12:29:43 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/// @brief calloc a 2d t_map array
/// @param rows number of the array
/// @param cols number of the array
/// @return the array
t_map	***allocate_2d_map_array(int32_t cols, int32_t rows)
{
	t_map	***map;
	int		i;
	int		j;

	map = calloc(cols + 1, sizeof(t_map **));
	i = 0;
	while (i < cols)
	{
		map[i] = calloc(rows + 1, sizeof(t_map *));
		j = 0;
		while (j < rows)
			map[i][j++] = calloc(1, sizeof(t_map));
		i++;
	}
	return (map);
}

/// @brief fill a 2d t_map array with the letter c
/// @param array to iterate
/// @param rows number of the array
/// @param cols number of the array
/// @param c the letter use for fill
void	fill_2d_map_array(t_map ***array, int32_t cols, int32_t rows, int32_t c)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < rows)
			array[i][j++]->id = c;
		i++;
	}
}

/// @brief print in terminal a 2d t_map array
/// @param array the array
void	print_2d_map_array(t_map ***array, int32_t cols, int32_t rows)
{
	int32_t x;
	int32_t y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			ft_printf("(%d,", array[x][y]->id);
			ft_printf("%d,", array[x][y]->tile_index);
			ft_printf("%d) ", array[x++][y]->life);
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
}