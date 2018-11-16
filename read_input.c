/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:52:14 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 17:31:24 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_input(char *input, t_piece **lst)
{
	int		ret;
	int		fd;
	char	buff[BUFF_SIZE + 1];
	char	c;

	*lst = 0;
	c = 'A';
	if((fd = open(input, O_RDONLY)) < -1)
	{
		ft_putstr("Can't open file");
		return (0);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		ft_putstr("test\n");
		if (valid_input(buff))
		{
			add_piece_lst(lst, buff, c);
			print_piece(lst_last(lst));
		}
		else
		{
			ft_putstr("not a valid input\n");
			return (-1);
		}
		c++;
		ft_strclr(buff);
		ret = read(fd, buff, 1);
		if (ret != 0 && buff[0] != '\n')
		{
			ft_putstr("Not a valid input\n");
			return (-1);
		}
	}
	ft_putstr("Finish reading file");
	return (1);
}
