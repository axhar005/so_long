/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:46 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 17:48:56 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	line_count(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	ft_itoc(int i)
{
	if (i >= 0 && i < 10)
		return (i + 48);
	return ('*');
}

void	print_2d_char_array(char **array)
{
	int	x;

	x = 0;
	while (array[x])
		ft_printf("%s\n", array[x++]);
	ft_printf("\n");
}

size_t	total_count(char **str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		count += ft_strlen(str[i]);
		i++;
	}
	return (count);
}

char	*ft_del_char(char *str, char c)
{
	char *new;
	size_t charnum;
	size_t i;
	size_t j;

	charnum = char_count(str, c);
	i = 0;
	j = 0;
	if (!str || charnum <= 0)
		return (str);
	new = ft_calloc(ft_strlen(str) - charnum + 1, sizeof(char));
	if (!new)
		return (str);
	while (str[i])
	{
		if (str[i] != c)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	return (ft_sfree(str), new);
}