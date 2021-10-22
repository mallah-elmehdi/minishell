
NAME = minishell
SEG = -fsanitize=address
FLAG = -Wall -Wextra -Werror
RL = -lreadline
MAIN = main.c

$(NAME): $(MAIN)
	@gcc $(FLAG) $(MAIN) $(SEG) $(RL) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr minishell.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all