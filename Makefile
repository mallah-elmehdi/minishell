
NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

LIB = src/cmd/cmd.a src/cd/cd.a src/env/env.a src/export/export.a src/pwd/pwd.a src/unset/unset.a src/utils/util.a src/echo/echo.a src/exit/exit.a src/other/other.a util/util.a
OBJ = *.o

MAIN = main.c

all: util_all src_all $(NAME)

$(NAME): $(MAIN)
	@gcc $(FLAG) $(SEG) -c $(MAIN)
	@gcc $(FLAG) $(SEG) $(OBJ) $(LIB) -o $(NAME)

clean: util_clean src_clean
	@rm -fr minishell.dSYM
	@rm -f *.o

fclean: util_fclean src_fclean clean
	@rm -f $(NAME)

re: util_re src_re fclean all

src_all:
	@make -C src/cd
	@make -C src/cmd
	@make -C src/env
	@make -C src/export
	@make -C src/pwd
	@make -C src/unset
	@make -C src/utils
	@make -C src/echo
	@make -C src/exit
	@make -C src/other
src_clean:
	@make clean -C src/cd
	@make clean -C src/cmd
	@make clean -C src/env
	@make clean -C src/export
	@make clean -C src/pwd
	@make clean -C src/unset
	@make clean -C src/utils
	@make clean -C src/echo
	@make clean -C src/exit
	@make clean -C src/other
src_fclean:
	@make fclean -C src/cd
	@make fclean -C src/cmd
	@make fclean -C src/env
	@make fclean -C src/export
	@make fclean -C src/pwd
	@make fclean -C src/unset
	@make fclean -C src/utils
	@make fclean -C src/echo
	@make fclean -C src/exit
	@make fclean -C src/other
src_re:
	@make re -C src/cd
	@make re -C src/cmd
	@make re -C src/env
	@make re -C src/export
	@make re -C src/pwd
	@make re -C src/unset
	@make re -C src/utils
	@make re -C src/echo
	@make re -C src/exit
	@make re -C src/other


util_all:
	@make -C util
util_clean:
	@make clean -C util
util_fclean:
	@make fclean -C util
util_re:
	@make re -C util