/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:30:01 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 15:11:24 by gly              ###   ########.fr       */
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

int					bigger_board(t_board **board, int nb_piece);
void				free_mat(char **mat, int n_row);
void				remove_piece(t_board *board, t_piece *piece);
void				place_piece(t_board *board, t_piece *piece);
int					test_pos(t_board *board, t_piece *piece);
int					advance_pos(t_board *bard, t_piece *piece);
t_board				*search_sol(t_piece *list);
void				print_board(t_board *board);
void				print_piece(t_piece *piece);

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_strnclr(char *s, size_t n);
void				ft_strdel(char **as);
t_piece				*lst_last(t_piece **lst);

int					add_piece_lst(t_piece **lst, char *buff, char c);
void				ft_lstdelall(t_piece **lst);
int					valid_input(char *buff);
int					open_input(char *input);
int					read_input(int fd, t_piece **lst);

#endif
