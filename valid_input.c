/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:03:38 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 12:05:49 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	adjacent_pound(int i, char *buff)
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

int			valid_input(char *buff)
{
	int		i;
	int		n;
	int		count;

	i = 0;
	n = 0;
	count = 0;
	if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n'
			|| buff[19] != '\n')
		return (0);
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
