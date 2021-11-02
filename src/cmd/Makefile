# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:37:52 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 13:37:53 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cmd.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = cmd.c init.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
