/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:55:23 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 14:04:13 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 1;
	temp = lst;
	if (!lst)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
