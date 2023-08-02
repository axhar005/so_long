/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:56:13 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/08/02 13:42:09 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*g(void)
{
	static t_game	game;

	return (&game);
}

t_parsing	*pars(void)
{
	static t_parsing	pars;

	return (&pars);
}

t_menu	*menu(void)
{
	static t_menu	menu;

	return (&menu);
}

t_lami	*lami(void)
{
	static t_lami	lami;

	return (&lami);
}
