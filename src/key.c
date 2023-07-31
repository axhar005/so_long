/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:20:19 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/31 17:25:20 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	norm1(keys_t key, keys_t *array, int32_t i)
{
	while (i < 10)
	{
		if (array[i] == key)
			return (false);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (array[i] == 0)
		{
			array[i] = key;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	norm2(keys_t key, keys_t *array, int32_t i)
{
	while (i < 10)
	{
		if (array[i] == key)
		{
			array[i] = 0;
			return (false);
		}
		i++;
	}
	return (false);
}

bool	is_key_pressed(keys_t key)
{
	static keys_t	array[10];
	int32_t			i;

	i = 0;
	if (mlx_is_key_down(g()->mlx, key))
	{
		return (norm1(key, array, i));
	}
	else
	{
		return (norm2(key, array, i));
	}
	return (false);
}

bool	mouse_button(int32_t x, int32_t y, int32_t width, int32_t height)
{
	if (g()->mouse.x > x && g()->mouse.x < x + width)
		if (g()->mouse.y > y && g()->mouse.y < y + height)
			return (true);
	return (false);
}