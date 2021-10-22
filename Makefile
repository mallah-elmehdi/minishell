
NAME = minishell
SEG = -fsanitize=address
FLAG = -Wall -Wextra -Werror
MAIN = main.c

$(NAME):
	@gcc $(FLAG) $(MAIN) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr minishell.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all