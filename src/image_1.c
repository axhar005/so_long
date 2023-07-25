/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:01:43 by oboucher          #+#    #+#             */
/*   Updated: 2023/07/25 13:28:58 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    del_menu_img(t_menu *menu)
{
    int i;

    i = 0;
    while (i < 5)
    {
        mlx_delete_image(g()->mlx, menu->button[i]);
        i++;
    }
}

void    init_menu_img(t_menu *menu)
{
    int i;

    i = 0;
    while (i < 5)
    {
        menu->button[i] = mlx_texture_to_image(g()->mlx, menu->tex[i]);
        i++;
    }
}