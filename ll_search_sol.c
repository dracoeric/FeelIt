/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_search_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:48:57 by erli              #+#    #+#             */
/*   Updated: 2018/11/19 12:46:54 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	nb_of_piece(t_piece *list)
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

static int	place_first_piece(t_board **board, t_piece **to_place,
		t_piece **first_piece)
{
	if (!bigger_board(board, nb_of_piece(*first_piece)))
		return (0);
	advance_pos(*board, *to_place);
	while (!test_pos(*board, *to_place))
	{
		if (!bigger_board(board, nb_of_piece(*first_piece)))
			return (0);
	}
	place_piece(*board, *to_place);
	*to_place = (*to_place)->next;
	return (1);
}

static void	search_loop(t_board **board, t_piece **to_place,
				t_piece **first_piece)
{
	while (*to_place != NULL)
	{
		if (!place_first_piece(board, to_place, first_piece))
			*board = NULL;
		while ((*first_piece)->pos.row >= 0 && *to_place != NULL)
		{
			while (!test_pos(*board, *to_place)
				&& (*first_piece)->pos.row >= 0)
			{
				if (advance_pos(*board, *to_place) == -1
					&& (*to_place)->prev != NULL)
				{
					*to_place = (*to_place)->prev;
					remove_piece(*board, *to_place);
					advance_pos(*board, *to_place);
				}
			}
			if ((*first_piece)->pos.row >= 0)
			{
				place_piece(*board, *to_place);
				*to_place = (*to_place)->next;
			}
		}
	}
}

t_board		*search_sol(t_piece *first_piece)
{
	t_board	*board;
	t_piece	*to_place;

	if (first_piece == NULL)
		return (NULL);
	board = NULL;
	to_place = first_piece;
	search_loop(&board, &to_place, &first_piece);
	return (board);
}
