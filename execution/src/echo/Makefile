# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:42:32 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 13:42:34 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = echo.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = echo.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
