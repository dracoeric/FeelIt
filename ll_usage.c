/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:09:22 by erli              #+#    #+#             */
/*   Updated: 2018/11/19 15:20:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	ft_putstr("Invalid number of arguments:\n");
	ft_putstr("Use './fillit filepath'\n");
	ft_putstr("with filepath, the path to a valid tetriminos file.\n");
}
