/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:48:09 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 13:17:23 by erli             ###   ########.fr       */
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

void	place_piece(t_board *board, t_piece *piece)
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

int		test_pos(t_board *board, t_piece *piece)
{
	int i;
	int j;
	int row;
	int col;

	row = piece->pos.row;
	col = piece->pos.col;
	i = 0;
	if (piece->pos.row < 0)
		return (0);
	while (i < piece->col)
	{
		j = 0;
		while (j < piece->row)
		{
			if (piece->form[i][j] != '.' && board->mat[row + i][col + j] != '.')
				return (0);
			j++;			
		}
		i++;
	}
	return (1);
}

int		advance_pos(t_board *board, t_piece *piece)
{
	if (piece->pos.row == -1)
	{
		piece->pos.row = 0;
		piece->pos.col = 0;
		return (1)
	}
	if (piece->pos.col + piece->col > board->size)
	{
		piece->pos.row++;;
		piece->pos.col = 0;
	}
	if (piece->pos.row + piece->row > board->size)
	{
		piece->pos.row = -1;
		piece->pos.col = -1;
		return (-1);
	}
	return (1);
}
