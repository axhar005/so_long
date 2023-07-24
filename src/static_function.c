/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:56:13 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/24 17:49:10 by oboucher         ###   ########.fr       */
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
	static t_parsing pars;

	return (&pars);
}