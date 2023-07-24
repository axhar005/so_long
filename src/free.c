/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:46:45 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 13:33:43 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    **ft_sfree_2d(void **ptr)
{
    void **temp;
    if (!ptr)
        return (NULL);
    temp = ptr;
    while (*ptr)
        free(*ptr++);
    free(temp);
    return(NULL);
}

void    free_map(void)
{
    int x;
    int y;
    
    x = 0;
    while (g()->map[x])
    {
        y = 0;
        while (g()->map[x][y])
        {
            ft_sfree(g()->map[x][y]);
            y++;
        }
        x++;
    }
    
}