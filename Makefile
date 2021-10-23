
NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror
RL = -lreadline

CMD = ./cmds/cmds.c ./cmds/init.c
CD = ./cmds/cd/cd.c ./cmds/cd/util.c
PWD = ./cmds/pwd/pwd.c ./cmds/pwd/util.c
UTIL = ./util/strnstr.c ./util/strdup.c ./util/calloc.c ./util/strlen.c ./util/error.c ./util/split.c ./util/free.c ./util/strjoin.c
MAIN = main.c

$(NAME): $(MAIN) $(CD) $(UTIL) $(CMD) $(PWD)
	@gcc $(FLAG) $(MAIN) $(CD) $(UTIL) $(CMD) $(PWD) $(SEG) $(RL) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr minishell.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all