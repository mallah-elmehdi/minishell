# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:08:58 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 15:08:59 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = util.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = export_unset.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
