# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:19:20 by emallah           #+#    #+#              #
#    Updated: 2021/11/02 13:19:21 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = util.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = error.c free.c split.c fsplit.c strcmp.c strdup.c strjoin.c strjoin_w_quote.c strlen.c strnstr.c strcpy.c isalpha.c isalnum.c isdigit.c
 
$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all
