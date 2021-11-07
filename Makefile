# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:13:35 by jcollon           #+#    #+#              #
#    Updated: 2021/11/07 23:31:42 by jcollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bot

all: $(NAME)

$(NAME): bot.c algo.c
	gcc -Wall -Wextra -o $(NAME) bot.c algo.c

re: fclean $(NAME)

fclean:
	rm -f $(NAME)