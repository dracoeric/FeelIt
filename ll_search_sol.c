/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:48:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/17 14:48:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

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

t_board	*search_sol(t_piece *first_piece)
{
	t_board	*board;
	t_piece	*to_place;
	int		is_err;

	is_err = 0;
	if (first_piece == NULL)
		return (NULL);
	board = NULL;
	to_place = first_piece;
	while (to_place != NULL)
	{
		is_err = bigger_board(&board, nb_of_piece(first_piece));
		if (is_err)
			return (NULL);
		printf("\nApres bigger board (size  = %d):\n", board->size);
		print_board(board);
		advance_pos(board, to_place);
		printf("first piece placed at row = %d, col = %d\n", to_place->pos.row, to_place->pos.col);
		place_piece(board, to_place);
		to_place = to_place->next;
		printf("\nfirst piece placed\n");
		print_board(board);
		while (first_piece->pos.row >= 0 && to_place != NULL)
		{
			while (!test_pos(board, to_place) && first_piece->pos.row >= 0)
			{
				if (advance_pos(board, to_place) == -1 && to_place->prev != NULL)
				{
					to_place = to_place->prev;
					remove_piece(board, to_place);
					printf("Remove piece\n");
					print_board(board);
					advance_pos(board, to_place);
				}
			}
			if (first_piece->pos.row >= 0)\
			{
				place_piece(board, to_place);
				printf("Placing piece\n");
				print_board(board);
				to_place = to_place->next;
			}
		}
	}
	return (board);
}
