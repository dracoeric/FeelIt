/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:30:01 by gly               #+#    #+#             */
/*   Updated: 2018/11/15 13:45:39 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

typedef struct		s_piece
{
	int				col;
	int				row;
	unsigned char	**form;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

#endif
