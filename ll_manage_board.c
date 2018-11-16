/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:32:14 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 15:57:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		smaller_square_size(int nb_piece)
{
	int area;
	int sqrt;

	if (nb_piece > 26 || nb_piece < 1)
		return (0);
	area = nb_piece * 4;
	sqrt = 2;
	while (sqrt * sqrt < area)
		sqrt++;
	return (sqrt);
}

static	void	fill_board(t_board *board)
{
	int i;
	int j;

	if (board == NULL)
		return;
	while (i < board->size + 3)
	{
		j = 0;
		while (j < board->size)
		{
			board->mat[i][j] = (i < board_size ? '.' : '\0');
			j++;
		}
		board->mat[i][board->size] = '\n';
		board->mat[i][board->size + 1] = '\0';
		i++;
	}
	
}

int 			bigger_board(t_board *board, int nb_piece)
{
	int		size;
	int 	i;

	size = (!board ? smaller_square_size(nb_piece) : board->size + 1);
	if (board != NULL)
		free_mat(board->mat);
	else
	{
		if (!(board = (t_board *)malloc(sizeof(T_board))))
			return (-1);
	}
	if (!(board->mat = (char **)malloc(sizeof(char *) * (size + 3))))
		return (-1);
	i = 0;
	while (i < size + 3)
	{
		if (!(board->mat[i] = (char *)malloc(sizeof(char) * (size + 2))))
			return (-1);
	}
	fill_board(board, board->size + 3);
	board->size = size;
	return (0);
}

void			free_mat(char **mat, int nr)
{
	int i;

	i = 0;
	while (i < nr)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
