/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:20:55 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 12:58:58 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		value;
	t_piece **lst;

	if (ac != 2)
		return (0);
	lst = malloc(sizeof(t_piece *));
	value = read_input(av[1], lst);
	ft_putnbr(value);
	return (1);
}
