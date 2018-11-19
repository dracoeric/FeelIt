/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:15:35 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 14:31:20 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_lstdel(t_piece *elem)
{
	int		i;

	i = 0;
	while (i < elem->row)
	{
		ft_strdel(&((elem->form)[i]));
		i++;
	}
	free(elem->form);
	free(elem);
}

void		ft_lstdelall(t_piece **lst)
{
	t_piece	*elem;
	t_piece *next;

	if (lst == 0 || *lst == 0)
		return ;
	elem = *lst;
	while (elem->next != 0)
	{
		next = elem->next;
		ft_lstdel(elem);
		elem = next;
	}
	ft_lstdel(elem);
	*lst = 0;
	return ;
}
