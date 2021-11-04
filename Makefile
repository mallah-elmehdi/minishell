NAME = minishell
SEG = -g -fsanitize=address
FLAG = -Wall -Wextra -Werror

FILE = parsing/parsing.a execution/execution.a

$(NAME): $(FILE)
	@gcc $(FLAG) $(SEG) $(FILE) main.c -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME)
	
all : parsing_all execution_all $(NAME)
clean: parsing_clean execution_clean
	@rm -fr *.o
fclean: parsing_fclean execution_fclean clean 
	@rm -fr $(NAME)
re: parsing_re execution_re fclean all

parsing_all:
	@make -C parsing
parsing_clean:
	@make clean -C parsing
parsing_fclean:
	@make fclean -C parsing
parsing_re:
	@make re -C parsing

execution_all:
	@make -C execution
execution_clean:
	@make clean -C execution
execution_fclean:
	@make fclean -C execution
execution_re:
	@make re -C execution