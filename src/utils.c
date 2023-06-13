/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:37 by oboucher          #+#    #+#             */
/*   Updated: 2023/06/06 17:12:26 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/// @brief calloc a 2d char array
/// @param rows number of the array
/// @param cols number of the array
/// @return the array
char	**allocate_2d_char_array(int32_t rows, int32_t cols)
{
	char	**arr;
	int32_t	i;

	arr = ft_calloc(cols + 1, sizeof(char *));
	i = 0;
	while (i <= cols)
		arr[i++] = ft_calloc(rows + 1, sizeof(char));
	return (arr);
}

/// @brief print in terminal a 2d char array
/// @param array the array
void	print_2d_char_array(char **array)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
			ft_printf("%c ", array[i][j++]);
		ft_printf("\n");
		i++;
	}
}

/// @brief fill a 2d char array with the letter c
/// @param array to iterate 
/// @param rows number of the array
/// @param cols number of the array
/// @param c the letter use for fill
void	fill_2d_char_array(char **array, int32_t rows, int32_t cols, char c)
{
	int32_t	i;
	int32_t	j;

	j = 0;
	while (j <= cols)
	{
		i = 0;
		while (i <= rows)
			array[j][i++] = c;
		ft_printf("\n");
		j++;
	}
}
