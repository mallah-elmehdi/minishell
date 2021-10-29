
NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

LIB = src/cd/cd.a src/cmds/cmds.a src/env/env.a src/export/export.a src/pwd/pwd.a util/util.a
OBJ = *.o

MAIN = main.c

all: util_all src_all $(NAME)

$(NAME): $(MAIN)
	@gcc $(FLAG) $(SEG) -c $(MAIN)
	@gcc $(FLAG) $(SEG) $(LIB) $(OBJ) -o $(NAME)

clean: util_clean src_clean
	@rm -fr minishell.dSYM
	@rm -f *.o

fclean: util_fclean src_fclean clean
	@rm -f $(NAME)

re: util_re src_re fclean all

src_all:
	@make -C src/cd
	@make -C src/cmds
	@make -C src/env
	@make -C src/export
	@make -C src/pwd
src_clean:
	@make clean -C src/cd
	@make clean -C src/cmds
	@make clean -C src/env
	@make clean -C src/export
	@make clean -C src/pwd
src_fclean:
	@make fclean -C src/cd
	@make fclean -C src/cmds
	@make fclean -C src/env
	@make fclean -C src/export
	@make fclean -C src/pwd
src_re:
	@make re -C src/cd
	@make re -C src/cmds
	@make re -C src/env
	@make re -C src/export
	@make re -C src/pwd


util_all:
	@make -C util
util_clean:
	@make clean -C util
util_fclean:
	@make fclean -C util
util_re:
	@make re -C util