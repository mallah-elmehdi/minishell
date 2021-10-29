NAME = export.a
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = export.c util.c update_export_pwd.c init.c

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) -c $(FILE)
	@ar -rc $(NAME) *.o 
	
all : $(NAME)

clean:
	@rm -fr *.o

fclean: clean
	@rm -fr $(NAME)

re: fclean all