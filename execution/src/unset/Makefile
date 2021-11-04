# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:02:04 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 15:02:05 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unset.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = unset.c util.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
