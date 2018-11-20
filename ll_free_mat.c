/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_free_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:46:56 by erli              #+#    #+#             */
/*   Updated: 2018/11/20 15:55:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	free_mat(char **mat, int nr)
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

void	free_board(t_board *board)
{
	if (board != NULL)
	{
		free_mat(board->mat, board->size + 3);
		free(board);
	}
}
