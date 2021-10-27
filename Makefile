
NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

LIB = src/cd/cd.a src/cmds/cmds.a src/env/env.a src/export/export.a src/pwd/pwd.a util/util.a
OBJ = *.o

MAIN = main.c

$(NAME): $(MAIN)
	@gcc $(FLAG) $(SEG) -c $(MAIN)
	@gcc $(FLAG) $(SEG) $(LIB) $(OBJ) -o $(NAME)
#-------------------
all: util_all src_all $(NAME)
clean: util_clean src_clean
	@rm -fr minishell.dSYM
fclean: util_fclean src_fclean clean
	@rm -f $(NAME)
re: util_re src_re fclean all
#--------------src
src_all:
	@make src/cd
	@make src/cmds
	@make src/env
	@make src/export
	@make src/pwd
src_clean:
	@make clean src/cd
	@make clean src/cmds
	@make clean src/env
	@make clean src/export
	@make clean src/pwd
src_fclean:
	@make fclean src/cd
	@make fclean src/cmds
	@make fclean src/env
	@make fclean src/export
	@make fclean src/pwd
src_re:
	@make re src/cd
	@make re src/cmds
	@make re src/env
	@make re src/export
	@make re src/pwd
#--------------util
util_all:
	@make util
util_clean:
	@make clean util
util_fclean:
	@make fclean util
util_re:
	@make re util