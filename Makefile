#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:00:21 by erli              #+#    #+#              #
#    Updated: 2018/11/16 16:16:36 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fillit

SRCS	=	ll_search_sol.c		ll_manage_piece.c	ll_manage_board.c	\

OBJSDIR	=	objs

OBS		=	$(addprefix &(OBJSDIR)/, %(SRCS:.c=.o);

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra

INCL	=	-I .

RM		=	rm -f


all		:	$(NAME)

$(NAME)	:	$(OBJS) fillit.h
			$(CC) $(CFLAG) $(INCL) $(OBJS) -o $(NAME)

%.o		:	%.c
			$(CC) $(CFLAG) $(INCL) $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean

