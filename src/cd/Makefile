NAME = cd.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = cd.c util.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o
	
all: $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all