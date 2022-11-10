# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:14:46 by xmatute-          #+#    #+#              #
#    Updated: 2022/11/09 21:44:32 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= clang
CFLAGS 	:= -Wall -Werror -Wextra

RM 		:= rm -rf

SANI 	:= -fsanitize=address -g3
val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all : server client

server : 
	make -C ft_printf
	$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a  -o server

client :
	make -C ft_printf
	$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a ft_atoi.c -o client

clean :
		$(RM) server client

fclean : clean
		make fclean -C ft_printf
		$(RM) server client

re : fclean all

.PHONY : all clean fclean re