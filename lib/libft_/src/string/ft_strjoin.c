/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:21:09 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 18:07:28 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/string.h"

/// @brief join 2 string in to one new string 
/// @param s1 is the initial string
/// @param s2 is the second string
/// @return a joined new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_memcpy(&new[s1_len], s2, s2_len + 1);
	return (new);
}
