/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:10:57 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 13:30:37 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*lst_last(t_piece **lst)
{
	t_piece *elem;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	elem = *lst;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
