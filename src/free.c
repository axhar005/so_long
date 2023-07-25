/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:46:45 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/25 15:46:33 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	**ft_sfree_2d(void **ptr)
{
	void	**temp;

	if (!ptr)
		return (NULL);
	temp = ptr;
	while (*ptr)
		free(*ptr++);
	free(temp);
	return (NULL);
}

void	free_map(t_tile ***map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			ft_sfree(map[x][y]);
			y++;
		}
		free(map[x]);
		x++;
	}
	free(map);
}

void	clean_all(void)
{
	del_img(&g()->old_img);
	del_img(&g()->img);
	del_texture();
	free_map(g()->map);
	ft_sfree_2d((void **)pars()->map);
	ft_sfree_2d((void **)pars()->mapf);
	ft_sfree_2d((void **)g()->p_animation.up);
	ft_sfree_2d((void **)g()->p_animation.down);
	ft_sfree_2d((void **)g()->p_animation.left);
	ft_sfree_2d((void **)g()->p_animation.right);
}