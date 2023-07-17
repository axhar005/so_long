/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:21:46 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/17 15:22:53 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void path_parsing(char *path)
{
    if (ft_strncmp(&path[ft_strlen(path)-4], ".ber", 4))
        ft_exit("Error, incorrect path (.ber needed)");
    if (ft_strlen(path) < 5)
        ft_exit("Error, incorrect path (name.ber needed)");
}

void map_is_rectangle(char **map)
{
    size_t x;
    size_t len;

    x = 0;
    len = ft_strlen(map[0]);
    if (len <= 0 || line_count(map) < 3)
        ft_exit("Error, rectangular map needed (more then 2 line in map)");
    while (map[x])
    {
        if (ft_strlen(map[x]) != len)
            ft_exit("Error, rectangular map needed");
        x++;
    }
}

void map_is_closed(void)
{
    size_t x;

    if (char_count(pars()->map[0], '1') != ft_strlen(pars()->map[0]) || char_count(pars()->map[pars()->height-1], '1') != ft_strlen(pars()->map[pars()->height-1]))
        ft_exit("Error, closed by walls needed");
    x = 1;
    while (x < pars()->height - 1)
    {
        if (pars()->map[x][0] != '1' || pars()->map[x][ft_strlen(pars()->map[x])-1] != '1')
            ft_exit("Error, closed by walls needed");
        x++;
    }
}

void    map_parsing_element(void)
{
    if (pars()->char_C < 1)
        ft_exit("Error, colectables 'C' needed");
    if (pars()->char_E < 1 || pars()->char_E > 1)
        ft_exit("Error, one exit 'E' needed");
    if (pars()->char_P < 1 || pars()->char_P > 1)
        ft_exit("Error, one player 'P' needed");
    if (pars()->char_0 + pars()->char_1 + pars()->char_E + pars()->char_P + pars()->char_C != total_count(pars()->map))
        ft_exit("Error, we need and accept only 5 char (0,1,E,P,C)");

}

void init_parsing(void)
{
    pars()->height = line_count(pars()->map);
    pars()->width = ft_strlen(pars()->map[0]);
    pars()->char_0 = char_count_2d(pars()->map, '0');
    pars()->char_1 = char_count_2d(pars()->map, '1');
    pars()->char_E = char_count_2d(pars()->map, 'E');
    pars()->char_P = char_count_2d(pars()->map, 'P');
    pars()->char_C = char_count_2d(pars()->map, 'C');
}

