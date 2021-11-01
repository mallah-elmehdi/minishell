NAME = unset.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = unset.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all