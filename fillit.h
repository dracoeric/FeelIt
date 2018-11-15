/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:30:01 by gly               #+#    #+#             */
/*   Updated: 2018/11/15 14:43:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_piece
{
	int				col;
	int				row;
	unsigned char	**form;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

typedef struct		s_board
{
	int				size;
	unsigned char	**mat;
}					t_board;

int		bigger_board(t_board *board, int nb_piece);
void	free_mat(char **mat, int n_row);

#endif
