/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:52:14 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 17:02:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	char	c;
	int		flag;

	*lst = 0;
	c = 'A';
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		flag = 0;
		if (valid_input(buff) == 0 || add_piece_lst(lst, buff, c) == 0)
			return (0);
		c++;
		ft_strnclr(buff, BUFF_SIZE + 1);
		ret = read(fd, buff, 1);
		if (ret != 0 && buff[0] != '\n')
			return (0);
		if (ret != 0)
			flag = 1;
	}
	return (flag == 1 ? 0 : 1);
}
