# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:01:14 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 15:01:15 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pwd.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = pwd.c util.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
