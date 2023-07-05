/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:56:13 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/05 12:28:46 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*g(void)
{
	static t_game *game;
	if (!game)
		game = ft_calloc(1, sizeof(t_game));
	return (game);
}