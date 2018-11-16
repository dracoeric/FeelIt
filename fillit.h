/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:30:01 by gly               #+#    #+#             */
/*   Updated: 2018/11/16 17:14:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 20

typedef struct		s_pos
{
	int				row;
	int				col;
}					t_pos;

typedef struct		s_piece
{
	int				col;
	int				row;
	char			**form;
	t_pos			pos;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

typedef struct		s_board
{
	int				size;
	 char			**mat;
}					t_board;

int		bigger_board(t_board **board, int nb_piece);
void	free_mat(char **mat, int n_row);
void	remove_piece(t_board *board, t_piece *piece);
void	place_piece(t_board *board, t_piece *piece);
int		test_pos(t_board *board, t_piece *piece);
int		advance_pos(t_board *bard, t_piece *piece);
t_board	*search_sol(t_piece *list);
void	print_board(t_board *board);

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_strclr(char *s);
t_piece	*lst_last(t_piece **lst);

int		add_piece_lst(t_piece **lst, char *buff, char c);
int		valid_input(char *buff);
int		read_input(char *input, t_piece **lst);


#endif
