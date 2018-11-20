/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:32:14 by erli              #+#    #+#             */
/*   Updated: 2018/11/20 15:36:27 by erli             ###   ########.fr       */
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

	i = 0;
	if (board == NULL)
		return ;
	while (i < board->size + 3)
	{
		j = 0;
		while (j < board->size)
		{
			board->mat[i][j] = (i < board->size ? '.' : '\0');
			j++;
		}
		board->mat[i][board->size] = '\n';
		board->mat[i][board->size + 1] = '\0';
		i++;
	}
}

static	int		first_board(t_board **board, int nb_piece)
{
	int		size;
	int		i;

	size = smaller_square_size(nb_piece);
	if (size == 0 || !((*board) = (t_board *)malloc(sizeof(t_board))))
		return (0);
	if (!((*board)->mat = (char **)malloc(sizeof(char *) * (size + 3))))
	{
		free(*board);
		return (0);
	}
	i = 0;
	while (i < size + 3)
	{
		if (!((*board)->mat[i] = (char *)malloc(sizeof(char) * (size + 2))))
		{
			free_mat((*board)->mat, i - 1);
			free(*board);
			return (0);
		}
		i++;
	}
	(*board)->size = size;
	fill_board(*board);
	return (1);
}

static	int		increase_board(t_board **board)
{
	int	size;
	int	i;

	size = (*board)->size + 1;
	free_mat((*board)->mat, (*board)->size + 3);
	if (!((*board)->mat = (char **)malloc(sizeof(char *) * (size + 3))))
	{
		free(*board);
		return (0);
	}
	i = 0;
	while (i < size + 3)
	{
		if (!((*board)->mat[i] = (char *)malloc(sizeof(char) * (size + 2))))
		{
			free_mat((*board)->mat, i - 1);
			free(*board);
			return (0);
		}
		i++;
	}
	(*board)->size = size;
	fill_board(*board);
	return (1);
}

int				bigger_board(t_board **board, int nb_piece)
{
	if (*board == NULL)
		return (first_board(board, nb_piece));
	else
		return (increase_board(board));
}
