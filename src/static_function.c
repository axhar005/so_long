/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:56:13 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/20 12:38:58 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*g(void)
{
	static t_game game;
	return (&game);
}

t_parsing	*pars(void)
{
	static t_parsing pars;
	return (&pars);
}