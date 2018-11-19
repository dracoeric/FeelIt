/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:02:25 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 15:31:46 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece	*fill_piece(t_piece *new, char *buff, int start, char c)
{
	int		i;
	int		j;
	int		p;

	if (!(new->form = (char **)malloc(sizeof(char *) * new->row)))
		return (NULL);
	i = 0;
	while (i < new->row)
	{
		if (!((new->form)[i] = (char *)malloc(sizeof(char) * new->col)))
			return (NULL);
		j = 0;
		while (j < new->col)
		{
			p = start + j + i * 5;
			new->form[i][j] = buff[p] == '#' ? c : '.';
			j++;
		}
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	new->pos.row = -1;
	new->pos.col = -1;
	return (new);
}

static t_piece	*new_piece(char *buff, char c)
{
	int		i;
	int		start;
	int		end;
	t_piece	*new;

	i = 0;
	start = -1;
	end = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			start = start == -1 ? i : start;
			start = start % 5 <= i % 5 ? start : (i % 5) + (start / 5) * 5;
			end = end % 5 <= i % 5 ? i : i + (end - i + 5) % 5;
		}
		i = (i - 3) % 5 ? i + 1 : i + 2;
	}
	if (!(new = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	new->row = (end - start) / 5 + 1;
	new->col = end % 5 - start % 5 + 1;
	new = fill_piece(new, buff, start, c);
	return (new);
}

int				add_piece_lst(t_piece **lst, char *buff, char c)
{
	t_piece	*elem;
	t_piece	*last;

	if (!(elem = new_piece(buff, c)))
		return (0);
	if (*lst == 0)
		*lst = elem;
	else
	{
		last = lst_last(lst);
		last->next = elem;
		elem->prev = last;
	}
	return (1);
}
