NAME = env.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = env.c util.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -o $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all