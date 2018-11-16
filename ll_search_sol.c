/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:48:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/16 13:50:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int		nb_of_piece(t_piece *list)
{
	int count;

	if (list == NULL)
		return (0);
	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

int		search_sol(t_piece *first_piece)
{
	t_board *board;
	t_piece *to_place;

	if (first_piece == NULL)
		return (-1);
	board = NULL;
	to_place = first_piece;
	while (to_place != NULL)
	{
		board = bigger_board;
		advance_piece(board, to_place);
		place_piece(board, to_place);
		to_piece = to_piece->next;
		while (first_piece->pos.row >= 0 && to_place != NULL)
		{
			while (!test_pos(board, to_place) && first_piece->pos.row >= 0)
			{
				if (advance_pos(board, to_place) == -1 && to_place->prev != NULL)
				{
					to_place = to_place->prev;
					remove_piece(board, to_place);
					advance_pos(board, to_place);
				}
			}
			if (first_piece->pos.row >= 0)\
			{
				place_piece(board, to_place);
				to_place = to_place->next;
			}
		}
	}
}
