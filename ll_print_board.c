/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_print_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:10:36 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 17:14:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_board *board)
{
	int i;

	i = 0;
	if (board == NULL)
		ft_putstr("error\n");
	else
	{
		while (i < board->size)
		{
			ft_putstr(board->mat[i]);
			i++;
		}
	}
}
