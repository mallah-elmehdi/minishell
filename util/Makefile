NAME = util.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = calloc.c error.c free.c realloc.c split.c strcmp.c strdup.c strjoin.c strlen.c strnstr.c strcpy.c isalpha.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all