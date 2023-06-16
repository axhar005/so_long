/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:46 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/06/16 14:26:06 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_strnum(char **str)
{
    int i;
    
    i = 0;
    if (!str)
        return (-1);
    while (str[i])
        i++;
    return (i);
}