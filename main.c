/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:58:18 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 17:01:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_piece		*lst;
	t_board		*solution;
	int			fd;

	if (ac != 2)
	{
		usage();
		return (0);
	}
	lst = 0;
	fd = open_input(av[1]);
	if (fd < 0 || read_input(fd, &lst) == 0)
	{
		ft_lstdelall(&list);
		ft_putstr("error\n");
		return (0);
	}
	solution = search_sol(lst);
	print_board(solution);
	ft_lstdelall(&lst);
	free_mat(solution->mat, solution->size + 3);
	free(solution);
	close(fd);
}
