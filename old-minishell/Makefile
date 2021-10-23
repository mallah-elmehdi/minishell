
NAME = minishell
GNL = getNextLine/*.c
TOOL = tool/*.c
COMMAND = command/*.c
EXEC = execution/*.c
PARSE = parsing/*.c
MAIN = main.c

$(NAME):
	@gcc -ltermcap -fsanitize=address $(GNL) $(TOOL) $(COMMAND) $(EXEC) $(PARSE) $(MAIN) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr a.out.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all