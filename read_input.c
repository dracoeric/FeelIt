/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:52:14 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 11:20:37 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*fill_piece(t_piece *new, char *buff, start)
{
	int		i;
	int		j;
	int		row;
	int		col;

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
			new->form[i][j] = buff[start + j + i * 5];
			j++;
		}
		i++;
	}
	return (new);
}


t_piece	*piece_new(char *buff)
{
	int		i;
	int		start;
	int		end;
	t_piece	*new;

	i = 0;
	start = -1;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			start = start == -1 ? i : start;
			end = i;
		}
		i = (i - 3) % 5 ? i + 1 : i + 2;
	}
	if (!(new = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	new->next = 0;
	new->pos.row = -1;
	new->pos.col = -1;
	new->row = (end - start) / 5 + 1;
	new->col = end % 5 - start % 5 + 1;
	new = fill_piece(new, buff);
	return (new);
}

int		add_piece(t_piece **lst, char *buff)
{
	t_piece	*elem;
	t_piece	*last;

	if (!(elem = create_new_piece(buff)))
		return (-1);
	last = lst_last(lst);
	last->next = elem;
	elem->prev = last;
}

int		adjacent_pound(int i, char *buff)
{
	int		count;

	count = 0;
	if ((i % 5) != 0 && buff[i - 1] == '#')
		count++;
	if (i < 15 && buff[i + 5] == '#')
		count++;
	if (i > 4 && buff[i - 5] == '#')
		count++;
	if ((i - 3) % 5 != 0 && buff[i + 1] == '#')
		count++;
	return (count);
}

int		valid_mat(char *buff)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	count = 0;
	while (i < 19)
	{
		if (buff[i] != '.' || buff[i] != '#')
			return (0);
		if (buff[i] == '#')
		{
			n++;
			count += adjacent_pound(i, buff);
		}
		i = (i - 3) % 5 ? i + 1 : i + 2;
	}
	if (count < 6 || n != 4)
		return (0);
	return (1);
}

int		valid_input(char *buff, t_piece **lst)
{

	if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n'
			|| buff[19] != '\n' || buff[20] != '\n' || !valid_mat(buff))
		return (0);
	return (1);
}

int		open_input(char *input)
{
	int		fd;

	fd = open(input, O_RDONLY);
	return (fd);
}

int		read_input(int fd, t_piece **lst)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (valid_input(buff, lst))
			add_piece(lst, buff);
		else
			return (-1);
	}
	return (1);
}
