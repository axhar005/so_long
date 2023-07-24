/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:18:35 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/22 15:41:16 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char **load_map(char *path)
{
    int fd;
    size_t i;
    size_t size;
    char **map;

    i = 0;
    size = 0;
    if (!path)
        ft_exit("Error: path not found");
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        close(fd);
        ft_exit("Error: file not found");
    }
    size = count_next_line(fd);
    if (size <= 0)
        return(NULL);
    close(fd);
    map = ft_gnl_calloc(size + 1, sizeof(char *));
    if (!map)
        return (NULL);
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        close(fd);
        map = (char **)ft_sfree_2d((void **)map);
        ft_exit("Error: file not found!!");
    }
    while (i < size)
    {
        map[i] = ft_del_char(get_next_line(fd), '\n');
        if (map[i] == NULL)
        {
            map = (char **)ft_sfree_2d((void **)map);
            close(fd);
            ft_exit("Error: when reading file (mayby empty line)");
        }
        i++;
    }
    close(fd);
    print_2d_char_array(map);
    return (map);
}

void load_in_map(void)
{
    int x;
    int y;
    
    x = 0;
    while (pars()->map[x])
    {
        y = 0;
        while (pars()->map[x][y])
        {
            if (pars()->map[x][y] == 'o' || pars()->map[x][y] == 'p' || pars()->map[x][y] == 'e')
                g()->map[y][x]->id = GRASS;
            else if (pars()->map[x][y] == '1')
                g()->map[y][x]->id = HILL;
            else if (pars()->map[x][y] == 'c')
                g()->map[y][x]->id = TREE;
            y++;
        }
        x++;
    }
}