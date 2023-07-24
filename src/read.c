/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:17:30 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 17:49:55 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	count_next_line(int fd)
{
	char *buffer;
	size_t count;

	count = 0;
	if (BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	buffer = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		count += char_count(buffer, '\n');
		ft_gnl_bzero(buffer, BUFFER_SIZE);
	}
	if (buffer)
		count++;
	buffer = ft_sfree(buffer);
	return (count);
}