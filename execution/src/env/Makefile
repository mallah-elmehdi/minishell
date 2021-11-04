# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:45:15 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 13:45:19 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = env.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = env.c init.c update.c util.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
