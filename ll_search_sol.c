/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:48:09 by erli              #+#    #+#             */
/*   Updated: 2018/11/15 16:28:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_board *board, t_piece *piece)
{
	int i;
	int j;

	i = 0;
	while (i < piece->col)
	{
		j = 0;
		while (j < piece->row)
		{
			if (piece->form[i][j] != '.')
				board->mat[piece->pos.row + i][piece->pos.col + j] = '.';
			j++;			
		}
		i++;
	}
}

void	place_piece(t_board *board, t_piece, *piece)
{
	int i;
	int j;

	i = 0;
	while (i < piece->col)
	{
		j = 0;
		while (j < piece->row)
		{
			if (piece->form[i][j] != '.')
				board->mat[piece->pos.row + i][piece->pos.col + j]
					= piece->form[i][j];
			j++;			
		}
		i++;
	}
}

int		test_next_pos(t_board *board, t_piece *piece)
{
	int i;
	int j;

	

}


int		ll_search_sol(t_piece *list)
{


}
