/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:16:02 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 18:02:04 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/memory.h"

/// @brief allo memory with mallloc and bzero to set all values 
/// @param count is how many value
/// @param size is size of value
/// @return a pointer with new zero value
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
	}
	return (ptr);
}
