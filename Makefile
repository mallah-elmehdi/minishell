
NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror
RL = -lreadline

CMD = ./cmds/cmds.c ./cmds/init.c
CD = ./cmds/cd/cd.c ./cmds/cd/util.c
PWD = ./cmds/pwd/pwd.c ./cmds/pwd/util.c
ENV = ./cmds/env/env.c ./cmds/env/util.c
EXPORT = ./cmds/export/export.c ./cmds/export/util.c
UTIL = ./util/strnstr.c ./util/strdup.c ./util/calloc.c ./util/strlen.c ./util/error.c ./util/split.c ./util/free.c ./util/strjoin.c ./util/strcmp.c
MAIN = main.c

$(NAME): $(MAIN) $(CD) $(UTIL) $(CMD) $(PWD) $(ENV) $(EXPORT)
	@gcc $(FLAG) $(MAIN) $(CD) $(UTIL) $(CMD) $(PWD) $(ENV) $(EXPORT) $(SEG) $(RL) -o $(NAME)
all : $(NAME)

clean:
	@rm -fr minishell.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all