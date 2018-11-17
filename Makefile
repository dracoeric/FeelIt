#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:00:21 by erli              #+#    #+#              #
#    Updated: 2018/11/17 15:49:05 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fillit

SRCS	=	ll_search_sol.c		ll_manage_piece.c	ll_manage_board.c	\
			ft_putchar.c		ft_putnbr.c			ft_putstr.c			\
			ft_strclr.c			add_piece_lst.c		lst_last.c			\
			lst_manipulators.c	valid_input.c		read_input.c		\
			ll_print_board.c	ll_free_mat.c		main.c \

OBJSDIR	=	objs

OBJS		=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra

INCL	=	-I .

RM		=	rm -f


all		:	$(NAME)

$(NAME)	:	$(OBJS) fillit.h
			$(CC) $(CFLAG) $(INCL) $(OBJS) -o $(NAME)

$(OBJSDIR)/%.o		:	%.c
			$(CC) -c $(CFLAG) $(INCL) $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean

