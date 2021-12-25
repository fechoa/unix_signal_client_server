# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 18:38:38 by gkelsie           #+#    #+#              #
#    Updated: 2021/10/25 21:20:45 by gkelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server
NAME_CLIENT	=	client

SRC_S		=	server.c
SRC_C		=	client.c

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

all				:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER)	:	$(SRC_S) minitalk.h
	$(CC) $(FLAGS) $(SRC_S) -o $(NAME_SERVER)
$(NAME_CLIENT)	:	$(SRC_C) minitalk.h
	$(CC) $(FLAGS) $(SRC_C) -o $(NAME_CLIENT)

clean			:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean			:	clean


re				:	fclean all

.PHONY			:	all clean fclean re bonus