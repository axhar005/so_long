/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:37 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/06 13:12:17 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int32_t	**allocate_2d_int_array(int32_t rows, int32_t cols)
{
	int32_t	**arr;
	int32_t	i;

	arr = malloc(rows * sizeof(int32_t *));
	i = 0;
	while (i++ < rows)
		arr[i] = ft_calloc(cols, sizeof(int32_t));
	return (arr);
}

/// @brief shown in terminal a 2d int32_t array
/// @param array adress of the array
/// @param rows of the array
/// @param height of the array
void	print_2d_int_array(int32_t **array, int32_t rows, int32_t cols)
{
	int32_t i;
	int32_t j;

	j = 0;
	while (j < cols)
	{
		i = 0;
		while (i++ < rows)
			ft_printf("%d ", array[i][j]);
		ft_printf("\n");
		j++;
	}
}