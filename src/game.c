/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:56:13 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/04 20:32:40 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game *g(void)
{
    static t_game *game;
    if (!game)
        game = ft_calloc(1, sizeof(t_game));
    return (game);
}