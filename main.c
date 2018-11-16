/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:58:18 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 17:18:40 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_piece		*lst;
	t_board		*solution;
;
	if (ac != 2)
	{
		ft_putstr("Too much or no arguments");
		return (0);
	}
	lst = 0;
	if (read_input(av[1], &lst) <= 0)
	{
		ft_putstr("Reading error\n");
		return (0);
	}
	solution = search_sol(lst);
	print_board(solution);
}
	
