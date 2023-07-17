/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:46:45 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/17 14:53:10 by olivierbouc      ###   ########.fr       */
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