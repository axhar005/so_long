/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:23:06 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/17 16:03:40 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void    flood_fill(char **map, int x, int y)
{
    if (map[x][y] == 'p' || map[x][y] == 'c' || map[x][y] == 'e' || map[x][y] == 'o' || map[x][y] == '1')
        return;
    if (map[x][y] == '0')
        map[x][y] = 'o';
    else if (map[x][y] == 'E')
        map[x][y] = 'e';
    else if (map[x][y] == 'C')
        map[x][y] = 'c';
    else if (map[x][y] == 'P')
        map[x][y] = 'p';

    flood_fill(map, x-1, y);
    flood_fill(map, x+1, y);
    flood_fill(map, x, y-1);
    flood_fill(map, x, y+1);
}

void after_flood(void)
{
    if (char_count_2d(pars()->map, 'e') != pars()->char_E)
        ft_exit("Error, exit obstructed");
    if (char_count_2d(pars()->map, 'c') != pars()->char_C)
        ft_exit("Error, on or more collectible obstructed");
}

void map_parsing(void)
{
    init_parsing();
    map_is_rectangle(pars()->map);
    map_is_closed();
    map_parsing_element();
    flood_fill(pars()->map, 1, 1);
    after_flood();
    print_2d_char_array(pars()->map);
    // pars()->map = (char **)ft_sfree_2d((void **)pars()->map);
}