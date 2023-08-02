/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:07:25 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 13:47:15 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	char_count_2d(char **str, char c)
{
	size_t	x;
	size_t	y;
	size_t	count;

	x = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == c)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

size_t	char_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_vec2	char_find_pos_2d(char **str, char c)
{
	size_t	x;
	size_t	y;
	t_vec2	pos;

	x = 0;
	pos.x = 0;
	pos.y = 0;
	if (!str)
		return (pos);
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == c)
			{
				pos.x = y;
				pos.y = x;
				return (pos);
			}
			y++;
		}
		x++;
	}
	return (pos);
}
