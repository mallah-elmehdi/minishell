# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 14:23:33 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 14:23:36 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = export.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = export.c update.c init.c util0.c util1.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
