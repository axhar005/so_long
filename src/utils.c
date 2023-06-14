/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:37 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/14 15:47:12 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/// @brief calloc a 2d t_map array
/// @param rows number of the array
/// @param cols number of the array
/// @return the array
t_map	***allocate_2d_map_array(int32_t rows, int32_t cols)
{
	t_map ***map;
	int x;
	int y;

	map = calloc(cols + 1, sizeof(t_map **));
	x = 0;
	while (x < cols)
	{
		map[x] = calloc(rows + 1, sizeof(t_map *));
		y = 0;
		while (y < rows)
			map[x][y++] = calloc(1, sizeof(t_map));
		x++;
	}
	return map;
}

/// @brief fill a 2d t_map array with the letter c
/// @param array to iterate
/// @param rows number of the array
/// @param cols number of the array
/// @param c the letter use for fill
void	fill_2d_map_array(t_map ***array, int32_t rows, int32_t cols, char c)
{
	int32_t	y;
	int32_t	x;

	x = 0;
	while (x < cols)
	{
		y = 0;
		while (y < rows)
			array[x][y++]->id = c;
		x++;
	}
}

/// @brief print in terminal a 2d t_map array
/// @param array the array
void	print_2d_map_array(t_map ***array)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			ft_printf("%c", array[x][y]->id);
			ft_printf("%d ", array[x][y++]->tile_index);
		}
		ft_printf("\n");
		x++;
	}
}