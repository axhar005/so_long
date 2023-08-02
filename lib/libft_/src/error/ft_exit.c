/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:15:09 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 15:00:21 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

void	ft_exit(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
